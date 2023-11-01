#include "serial.h"

volatile int serialFlag = 1;

serial::~serial()
{
    if (fd != 0)
    {
        close(fd);
    }
}

void serial::initTty()
{

    // 声明设置串口的结构体
    struct termios termios_new;

    // 先清空该结构体
    bzero(&termios_new, sizeof(termios_new));

    //	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
    cfmakeraw(&termios_new);

    // 设置波特率
    // termios_new.c_cflag=(B9600);
    cfsetispeed(&termios_new, B9600);
    cfsetospeed(&termios_new, B9600);

    // CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。
    termios_new.c_cflag |= CLOCAL | CREAD;

    // 通过掩码设置数据位为8位
    termios_new.c_cflag &= ~CSIZE;
    termios_new.c_cflag |= CS8;

    // 设置无奇偶校验
    termios_new.c_cflag &= ~PARENB;

    // 一位停止位
    termios_new.c_cflag &= ~CSTOPB;
    // tcflush(fd,TCIFLUSH);

    // 可设置接收字符和等待时间，无特殊要求可以将其设置为0
    termios_new.c_cc[VTIME] = 10;
    termios_new.c_cc[VMIN] = 1;

    // 用于清空输入/输出缓冲区
    tcflush(fd, TCIFLUSH);

    // 完成配置后，可以使用以下函数激活串口设置
    tcsetattr(fd, TCSANOW, &termios_new);
    // printf("初始化串口成功\n");
}

unsigned char serial::CalBCC(unsigned char *buf, int n)
{
    int i;
    unsigned char bcc = 0;
    for (i = 0; i < n; i++)
    {
        bcc ^= *(buf + i); // buf[i]
    }
    return (~bcc);
}

int serial::PiccRequest(int fd)
{
    unsigned char WBuf[128], RBuf[128];
    int ret, len = 0;
    fd_set rdfd;

    memset(WBuf, 0, 128); // 数组清空
    memset(RBuf, 0, 128);

    WBuf[0] = 0x07;                      // 帧长= 7 Byte
    WBuf[1] = 0x02;                      // 包号= 0 , 命令类型
    WBuf[2] = 0x41;                      // 命令= 'A'
    WBuf[3] = 0x01;                      // 信息长度
    WBuf[4] = 0x52;                      // 请求模式:  ALL=0x52
    WBuf[5] = CalBCC(WBuf, WBuf[0] - 2); // 校验和
    WBuf[6] = 0x03;                      // 结束标志

    while (1)
    {
        FD_ZERO(&rdfd);
        FD_SET(fd, &rdfd);
        tcflush(fd, TCIFLUSH);
        // 发送A命令
        write(fd, WBuf, 7);

        // 多路复用来监测串口文件描述符是否有数据可读
        ret = select(fd + 1, &rdfd, NULL, NULL, &timeout); // 监测文件描述符的变化
        switch (ret)
        {
        case -1:
            perror("select error\n");
            break;
        case 0:
            len++; // 3次请求超时后，退出该函数
            if (len == 3)
            {
                len = 0;
                return -1;
            }
            // printf("Request timed out.\n");
            break;
        default:
            usleep(10000); // 延时一丢丢，防止硬件模块读写速度跟不上while(1)
            ret = read(fd, RBuf, 8);

            if (ret < 0)
            {
                printf("len = %d, %d\n", ret, errno);
                break;
            }

            // printf("RBuf[2]:%x\n", RBuf[2]);
            if (RBuf[2] == 0x00) // 应答帧状态部分为0 则请求成功
            {
                return 0;
            }
            break;
        }
        usleep(100000);
    }

    return -1;
}

int serial::PiccAnticoll(int fd)
{

    // printf("fd = %d\n", fd);

    unsigned char WBuf[128], RBuf[128];
    int ret = 1,  len = 0;
    fd_set rdfd;

    memset(WBuf, 0, 128);
    memset(RBuf, 1, 128);

    WBuf[0] = 0x08;                      // 帧长= 8 Byte
    WBuf[1] = 0x02;                      // 包号= 0 , 命令类型= 0x01
    WBuf[2] = 0x42;                      // 命令= 'B'
    WBuf[3] = 0x02;                      // 信息长度= 2
    WBuf[4] = 0x93;                      // 防碰撞0x93
    WBuf[5] = 0x00;                      // 位计数0
    WBuf[6] = CalBCC(WBuf, WBuf[0] - 2); // 校验和
    WBuf[7] = 0x03;                      // 结束标志

    while (1)
    {
        tcflush(fd, TCIFLUSH);
        FD_ZERO(&rdfd);
        FD_SET(fd, &rdfd);
        // 发送B命令
        write(fd, WBuf, 8);
        // 多路复用来监测串口文件描述符是否有数据可读
        ret = select(fd + 1, &rdfd, NULL, NULL, &timeout);
        switch (ret)
        {
        case -1:
            perror("select error\n");
            break;
        case 0:
            len++;
            if (len == 10)
            {
                len = 0;
                return -1;
            }
            printf("超时...\n");
            break;

        default:
            usleep(10000);
            ret = read(fd, RBuf, 10);
            if (ret < 0)
            {
                printf("ret = %d\n", ret);
                break;
            }
            if (RBuf[2] == 0x00) // 应答帧状态部分为0 则获取ID 成功
            {
                cardid = (RBuf[4] << 24) | (RBuf[5] << 16) | (RBuf[6] << 8) | RBuf[7];

                return 0;
            }
        }
    }

    return -1;
}

int serial::openSerial()
{
    // 以非阻塞的方式打开
    fd = open("/dev/ttySAC1", O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0)
    {
        printf("Open /dev/ttySAC1 fail!\n");
        return -1;
    }
    // printf("打开串口驱动\n");
    return 0;
}

int serial::getcardid() // 获取卡号
{
    return this->cardid;
}

void serial::run()
{
    // 打开串口驱动
    openSerial();
    initTty();
    printf("开启串口读卡线程\n");
    int ret;
    // 设置了1秒钟的多路复用超时时间--》原因读卡模块有可能存在故障，多路复用不可能一直傻乎乎地阻塞监测
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    while (serialFlag)
    {
        // 发送A命令
        ret = PiccRequest(fd);
        if (ret == -1) // 若是请求超时退出，必须要关闭串口后，重新打开才能再次读取数据
        {
            usleep(500000);
            if (fd > 0)
                close(fd);
            // 打开串口文件
            openSerial();
            /*初始化串口*/
            initTty();
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            continue; // 发送A命令失败了，重新继续发送A命令，按在地上摩擦
        }
        else
        {
            printf("ok\n");
        }
        // 发送B命令 和获取卡号
        ret = PiccAnticoll(fd);

        // 若获取的cardid为0，或获取id超时，则需重新发送'A'命令
        if (cardid == 0 || ret == -1)
            continue;
        else if (ret == 0)
        {
            // printf("卡号为:%x\n", cardid);  //打印cardid号
            emit mySignal(cardid); // 发送信号
            usleep(500000);
            //break;
        }
    }
    printf("关闭串口读卡线程\n");

    return;
}

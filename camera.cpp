#include "camera.h"

#define WIDTH 320
#define HEIGHT 240
#define LCD_WIDTH 800
#define LCD_HEIGHT 480

volatile int cameraFlag=1;//控制摄像头采集图像线程的开启和关闭
unsigned char rgb_data[640 * 480 * 4]; // 存储转换后的rgb像素值
unsigned int *g_pfd;
struct mpmap // 存放内存映射的4个分区首地址
{
    unsigned char *mptr;
    unsigned int length;
} map[4];


struct v4l2_format myfmt;
struct v4l2_buffer mapbuffer;
struct v4l2_requestbuffers reqbuffer;
// 描点操作
void lcd_draw_point(int x, int y, unsigned int color)
{
    // 检查坐标是否越界，如果越界则不进行绘制
    if (x >= 0 && x < LCD_WIDTH && y >= 0 && y < LCD_HEIGHT)
    {
        *(g_pfd + y * LCD_WIDTH + x) = color;
    }
}

void YUYVtoRGB(unsigned char *yuyv, unsigned char *rgbdata, int width, int height)
{
    for (int i = 0; i < width * height / 2; i++)
    {
        unsigned char y0 = yuyv[i * 4];
        unsigned char u0 = yuyv[(i * 4) + 1];
        unsigned char y1 = yuyv[(i * 4) + 2];
        unsigned char v1 = yuyv[(i * 4) + 3];

        int c0 = y0 - 16;
        int d0 = u0 - 128;
        int e0 = v1 - 128;

        int c1 = y1 - 16;
        int d1 = u0 - 128;
        int e1 = v1 - 128;

        int r0 = (298 * c0 + 409 * e0 + 128) >> 8;
        int g0 = (298 * c0 - 100 * d0 - 208 * e0 + 128) >> 8;
        int b0 = (298 * c0 + 516 * d0 + 128) >> 8;

        int r1 = (298 * c1 + 409 * e1 + 128) >> 8;
        int g1 = (298 * c1 - 100 * d1 - 208 * e1 + 128) >> 8;
        int b1 = (298 * c1 + 516 * d1 + 128) >> 8;

        r0 = (r0 < 0) ? 0 : (r0 > 255) ? 255
                                       : r0;
        g0 = (g0 < 0) ? 0 : (g0 > 255) ? 255
                                       : g0;
        b0 = (b0 < 0) ? 0 : (b0 > 255) ? 255
                                       : b0;

        r1 = (r1 < 0) ? 0 : (r1 > 255) ? 255
                                       : r1;
        g1 = (g1 < 0) ? 0 : (g1 > 255) ? 255
                                       : g1;
        b1 = (b1 < 0) ? 0 : (b1 > 255) ? 255
                                       : b1;

        rgbdata[i * 6] = r0;
        rgbdata[i * 6 + 1] = g0;
        rgbdata[i * 6 + 2] = b0;
        rgbdata[i * 6 + 3] = r1;
        rgbdata[i * 6 + 4] = g1;
        rgbdata[i * 6 + 5] = b1;
    }
}

void lcd_show_rgb(unsigned char *rgbdata, int w, int h, int x, int y)
{
    // 确保传递的坐标在有效范围内
    if (x < 0 || x + w > LCD_WIDTH || y < 0 || y + h > LCD_HEIGHT)
    {
        // printf("所选区域超出LCD屏幕范围，无法显示。\n");
        return;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // 计算RGB数据索引
            int rgb_index = ((i * w + j) * 3);
            unsigned int color = (rgbdata[rgb_index] << 16) | (rgbdata[rgb_index + 1] << 8) | rgbdata[rgb_index + 2];

            // 显示像素颜色
            lcd_draw_point(x + j, y + i, color);
        }
    }
}


camera::camera()
{
    // 打开/dev/fb0
    g_fd_lcd = open("/dev/fb0", O_RDWR);

    if (g_fd_lcd < 0)
    {
        printf("open lcd fail\n");
        return;
    }

    // 将设备文件/dev/fb0映射到内存
    g_pfd = (unsigned int *)mmap(NULL,                       // 映射区的起始地址由系统自动分配
                                  LCD_WIDTH * LCD_HEIGHT * 4, // 映射内存的大小，往往填写文件的大小
                                  PROT_READ | PROT_WRITE,     // 映射区的保护形式，当前是可读可写
                                  MAP_SHARED,                 // 共享，把映射内存的数据同步到文件
                                  g_fd_lcd,                   // 映射的文件描述符
                                  0);                         // 文件的偏移量，0就不需要进行的偏移

    if (g_pfd == MAP_FAILED)
    {
        printf("mmap fail\n");
        return;
    }
    image=new QImage(WIDTH, HEIGHT, QImage::Format_RGB888);
}

int camera::cameraInit()
{
    // 打开摄像头驱动
    camerafd = open("/dev/video7", O_RDWR);
    if (camerafd == -1)
    {
        printf("打开摄像头失败\n");
        return -1;
    }
    // 设置摄像头画面参数

    bzero(&myfmt, sizeof(myfmt));
    myfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width = WIDTH;
    myfmt.fmt.pix.height = HEIGHT;
    myfmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;

    ret = ioctl(camerafd, VIDIOC_S_FMT, &myfmt);
    if (ret == -1)
    {
        perror("设置摄像头画面参数失败\n");
        return -1;
    }

    // 申请内核空间

    reqbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    reqbuffer.count = 4;
    reqbuffer.memory = V4L2_MEMORY_MMAP;

    ret = ioctl(camerafd, VIDIOC_REQBUFS, &reqbuffer);
    if (ret < 0)
    {
        perror("申请空间失败");
    }

    // 映射内存地址
    for (int i = 0; i < 4; i++)
    {
        bzero(&mapbuffer, sizeof(mapbuffer));
        mapbuffer.index = i;
        mapbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        mapbuffer.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(camerafd, VIDIOC_QUERYBUF, &mapbuffer);
        if (ret < 0)
        {
            perror("查询内核空间失败");
        }

        map[i].length = mapbuffer.length;
        map[i].mptr = (unsigned char *)mmap(NULL, mapbuffer.length, PROT_READ | PROT_WRITE, MAP_SHARED, camerafd, mapbuffer.m.offset);

        ret = ioctl(camerafd, VIDIOC_QBUF, &mapbuffer);
        if (ret < 0)
        {
            perror("入队失败");
        }
    }

    // 启动摄像头开始采集画面
    // enum v4l2_buf_type type;
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret = ioctl(camerafd, VIDIOC_STREAMON, &type);
    if (ret < 0)
    {
        perror("启动失败");
    }
    return 0;
}

int camera::cameraCapture()//采集摄像头图像数据
{
  QPixmap pixmap;
    for (int i = 0; i < 4; i++)
    {
        // 出队
        bzero(&mapbuffer, sizeof(mapbuffer));
        mapbuffer.index = i;
        mapbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        mapbuffer.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(camerafd, VIDIOC_DQBUF, &mapbuffer);
        if (ret < 0)
        {
            perror("出队失败");
            return -1;
        }
        // 将YUYV转换成RGB格式 显示在lcd上
        YUYVtoRGB(map[i].mptr, rgb_data, WIDTH, HEIGHT);
        usleep(1000);
       // lcd_show_rgb(rgb_data, WIDTH, HEIGHT, 5, 5);
        // 更新QImage对象
        *image = QImage(rgb_data, WIDTH, HEIGHT, QImage::Format_RGB888);
        // 更新QPixmap对象
        pixmap = QPixmap::fromImage(*image).scaled(mylabel->width(), mylabel->height());
        mylabel->setScaledContents(true);
        mylabel->setPixmap(pixmap);
        // 再入队
        ret = ioctl(camerafd, VIDIOC_QBUF, &mapbuffer);
        if (ret < 0)
        {
            perror("入队失败");
            return -1;
        }
        // 清零已经处理过的内存区域
        bzero(map[i].mptr, map[i].length);
    }
    usleep(1000);
    // bzero(rgb_data,sizeof(rgb_data));
    memset(rgb_data,0,sizeof(rgb_data));
    return 0;
}

int camera::cameraClose()//关闭摄像头释放资源
{
    ret = ioctl(camerafd, VIDIOC_STREAMOFF, &myfmt);
    if (ret < 0)
    {
        printf("停止失败\n");
        return -1;
    }
    for (int i = 0; i < 4; i++)
    {
        printf("释放内存映射块\n");
        munmap(map[i].mptr, map[i].length);
    }
    munmap(g_pfd, LCD_WIDTH * LCD_HEIGHT*4);
    if(g_fd_lcd>0)
    {
        printf("close lcd_fd\n");
        close(g_fd_lcd);
    }

    myfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if(camerafd>0)
    {
        printf("close camerafd\n");
         close(camerafd);
    }

//    if(mylabel!=nullptr)
//        delete mylabel;
    return 0;
}

QImage camera::camerPthoto()//拍照
{
    printf("拍照成功\n");
    QImage image(rgb_data,WIDTH,HEIGHT,QImage::Format_RGB888);
    //将获取到的QImage对象返回给主窗口函数，再由主窗口函数发送到api接口
    return image;
}

void camera::setLabel(QLabel *label)//获取主窗口的label组件，用于显示摄像头画面
{
    this->mylabel=label;
}

void camera::run()
{
    printf("开启摄像头线程\n");
    while(cameraFlag)
    {
        cameraCapture();
    }
    printf("关闭摄像头线程\n");
    return ;
}

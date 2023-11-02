#ifndef CAMERA_H
#define CAMERA_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <linux/input.h> //输入子系统模型有关的头文件
#include <sys/mman.h>    //内存映射有关的头文件
#include <sys/wait.h>
#include <signal.h> //跟signal有关的头文件
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include<stropts.h>
#include<linux/videodev2.h>
#include <linux/fb.h>
#include<QImage>
#include<QPixmap>
#include<QLabel>
#include<QThread>
#include<QMainWindow>

class camera:public QThread
{
public:
    camera();
    //初始化摄像头
    int cameraInit();
    //采集图像
    int cameraCapture();
    //关闭摄像头
    int cameraClose();
    //拍照
    QImage camerPthoto();

    void setLabel(QLabel *label);

    void run();//重写QThread类里面的run函数，创建线程并运行

private:
    int camerafd;//摄像头文件描述符
    int ret;//标志位
    int g_fd_lcd;
    QLabel *mylabel;
    QImage *image;
};

#endif // CAMERA_H

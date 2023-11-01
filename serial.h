#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include<QMainWindow>
#include<QThread>


class serial:public QThread
{
    Q_OBJECT

public:                 
    serial(QObject *parent = nullptr) : QThread(parent) {}
    ~serial();
    void initTty();//串口的初始化
    unsigned char CalBCC(unsigned char *buf, int n);//求校验位
    int PiccRequest(int fd);//发送'A'命令
    int PiccAnticoll(int fd);//发送'B'命令
    int openSerial();//打开串口
    int getcardid();
    void run();//线程运行函数

private:
    volatile unsigned int cardid ;//卡号
    int fd;//串口驱动文件描述符
    struct timeval timeout;//超时时间
signals:
    void mySignal(int value);

};

#endif // SERIAL_H

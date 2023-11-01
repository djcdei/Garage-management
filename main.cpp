#include "mainwindow.h"
#include<QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//或者"GBK",不分大小写
    QTextCodec::setCodecForLocale(codec);
    MainWindow w;
    w.show();
    return a.exec();
}

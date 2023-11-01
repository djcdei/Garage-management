#include "advertisement.h"

Advertisement::Advertisement(QLabel *label) : mylabel(label)
{
    // 存放图片的母文件路径，替换为实际路径
    QString photoDirectory = "/home/pthoto";
    QDir directory(photoDirectory);

    // 检查目录是否存在
    if (directory.exists()) {
        QStringList fileList = directory.entryList(QDir::Files);

        foreach (QString fileName, fileList) {
            QString filePath = directory.absoluteFilePath(fileName);

            // 检查文件是否存在和是否可读取
            QFileInfo fileInfo(filePath);
            if (fileInfo.exists() && fileInfo.isFile() && fileInfo.isReadable()) {
                // 获取文件扩展名并转换为小写，以便不区分大小写比较
                QString extension = fileInfo.suffix().toLower();

                // 检查文件扩展名，只添加符合条件的文件路径
                if (extension == "jpg" || extension == "bmp" || extension == "png") {
                    pthotoList.append(filePath);
                    qDebug() << "已添加文件：" << filePath; // 打印完整的文件路径
                }
            }
        }
    } else {
        qDebug() << "目录不存在：" << photoDirectory;
    }
}

void Advertisement::startAdvertising(int interval)
{
    if (pthotoList.isEmpty()) {
        qDebug() << "广告目录为空";
        return;
    }

    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &Advertisement::showNextImage);
    myTimer->start(interval);
}

void Advertisement::stopAdvertising()
{
    if (myTimer) {
        myTimer->stop();
        myTimer->deleteLater();
    }
}

void Advertisement::showNextImage()
{

    if (cnt == pthotoList.size()||cnt<0) {
        cnt = 0; // 重置计数器
    }
    QPixmap mymap;
    if (mymap.load(pthotoList.at(cnt)))
    {
        mymap = mymap.scaled(mylabel->size(), Qt::KeepAspectRatio);
        mylabel->setScaledContents(true);
        mylabel->setPixmap(mymap);
    }
    else
    {
        // 处理加载图片失败的情况
        qDebug() << "Failed to load image: " << pthotoList.at(cnt);
    }
    cnt++;
}

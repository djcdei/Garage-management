#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QLabel>
#include <QTimer>

class Advertisement : public QObject
{
    Q_OBJECT

public:
    Advertisement(QLabel *label);
    void startAdvertising(int interval);
    void stopAdvertising();

private slots:
    void showNextImage();

private:
    QLabel *mylabel;
    QStringList pthotoList;
    QTimer *myTimer;
    int cnt = 0;
};

#endif // ADVERTISEMENT_H

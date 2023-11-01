#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"camera.h"
#include"serial.h"
#include"sqlite3.h"
#include"carspacedialog.h"
#include"admindialog.h"
#include"advertisement.h"
#include<time.h>
#include<QTimer>
#include<QDateTime>
#include<QBuffer>
#include<QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QMainWindow>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
#include <QSignalMapper>
#include <QPushButton>
#include<QMap>
#include<QStringList>
#include<QDir>
#include<QPixmap>
#include<QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getPlatenum();//获取当前车牌号

public slots:
    void handleButtonClicked();//关联两个切换按钮

private slots:
    void on_pb_exit_clicked();
    void cardidfun(int value);

    void on_pb_admlogin_clicked();
    void netReply(QNetworkReply *rep);
    void on_pb_userlogin_clicked();
    void setLabelColor();


private:
    Ui::MainWindow *ui;
    camera *mycamera;//摄像头对象
    serial *myserial;//串口对象
    sqlite3 *mysqlite;
    Advertisement *myadver;//广告播放对象
    QImage myimage;
    QNetworkAccessManager myManager;
    int starttime;//入库时间
    int endtime;//出库时间
    QString cardid;//车卡号
    QString platenum;//车牌号
    float balance;//余额
    int position;//位置
    class adminDialog *adminDialog;
    class cardDialog *cardialog;
    class CarSpaceDialog *carspace;
    QTimer *mytimer;
    QLabel **p_lab;
    QString originalStyle;//保留控件原有样式



};
#endif // MAINWINDOW_H

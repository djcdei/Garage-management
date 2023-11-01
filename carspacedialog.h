#ifndef CARSPACEDIALOG_H
#define CARSPACEDIALOG_H
#include<QString>
#include"QSignalMapper"
#include"sqlite3.h"
#include<QMessageBox>
#include<QDebug>
#include <QDialog>
#include <QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>

namespace Ui {
class CarSpaceDialog;
}

class CarSpaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarSpaceDialog(QWidget *parent = nullptr);
    ~CarSpaceDialog();
    void setPlatenum(QString _platenum);//获取当前车牌号
    void setPbColor();//根据车位表中的车位号，给对应车位按钮上色
    int getPosition();//获取车位信息

private slots:
    void on_pb_back_clicked();
    void buttonSlot(int num);//自己定义的槽函数，获取车位点击信息

private:
    Ui::CarSpaceDialog *ui;
    QString platenum;//保存车牌号
    class sqlite3 *mysqlite;
    QSqlDatabase mybase;
    QPushButton **p_bt;//二维指针，指向存放按钮指针的数组
    QString originalStyle;//保存旧样式
    int position;//保存车位信息

};

#endif // CARSPACEDIALOG_H

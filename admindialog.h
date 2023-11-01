#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H
#include<QString>
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlError>
#include <QDialog>
#include<QString>
#include<QMessageBox>
#include<QTableWidgetItem>
namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminDialog(QWidget *parent = nullptr);
    ~adminDialog();
    void updateTablewidgetData();//更新表格列表框

private slots:
    void on_pb_back_clicked();

    void on_pb_login_clicked();


    void on_pb_back2_clicked();



    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::adminDialog *ui;
    QSqlDatabase mybase;
};

#endif // ADMINDIALOG_H

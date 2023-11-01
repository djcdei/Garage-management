#ifndef CARDDIALOG_H
#define CARDDIALOG_H

#include <QDialog>

namespace Ui {
class cardDialog;
}

class cardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cardDialog(QWidget *parent = nullptr);
    ~cardDialog();

private:
    Ui::cardDialog *ui;
};

#endif // CARDDIALOG_H

#ifndef USER_REGISTER_H
#define USER_REGISTER_H

#include <QDialog>
#include <QString>
#include <qsqlquery.h>
#include "QMessageBox"

namespace Ui {
class user_register;
}

class user_register : public QDialog
{
    Q_OBJECT

public:
    explicit user_register(QWidget *parent = nullptr);
    ~user_register();

private slots:
    void on_register_exit_clicked();//退出注册界面

    void on_register_sure_clicked();//确认注册

private:
    Ui::user_register *ui;
};

#endif // USER_REGISTER_H

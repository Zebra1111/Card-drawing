#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "user_register.h"
#include "user_draw.h"
#include "manager.h"
#include "user_info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_check_clicked();//登录按键

    void on_login_register_clicked();//注册按键

    void on_exit_clicked();//退出按键

private:
    Ui::login *ui;
    user_draw draw;//用户界面
    manager ad;//管理界面
    user_info *info;//获取信息单例
};
#endif // LOGIN_H

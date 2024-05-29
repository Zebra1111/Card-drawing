#ifndef MANAGE_USER_H
#define MANAGE_USER_H

#include <QDialog>
#include "user_info.h"
#include "update_info.h"
#include "qvariant.h"

namespace Ui {
class manage_user;
}

class manage_user : public QDialog
{
    Q_OBJECT

public:
    explicit manage_user(QWidget *parent = nullptr);
    ~manage_user();
    void show_all_user_info();//展示用户信息

private slots:
    void on_manage_user_select_clicked();//搜索功能

    void on_manage_user_update_clicked();//修改功能

    void on_manage_user_delete_clicked();//删除功能

    void on_manage_user_return_clicked();//返回功能

private:
    Ui::manage_user *ui;
    user_info *info;
};

#endif // MANAGE_USER_H

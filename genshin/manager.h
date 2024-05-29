#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include "user_info.h"
#include "manage_user.h"

namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = nullptr);
    ~manager();
    void get_info(user_info *);//获取数据

private slots:
    void on_ManageUser_clicked();//管理用户

    void on_ManageExit_clicked();//退出

private:
    Ui::manager *ui;
    user_info * info;
};

#endif // MANAGER_H

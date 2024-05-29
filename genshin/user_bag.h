#ifndef USER_BAG_H
#define USER_BAG_H

#include <QDialog>
#include"item_info.h"

namespace Ui {
class user_bag;
}

class user_bag : public QDialog
{
    Q_OBJECT

public:
    explicit user_bag(QWidget *parent = nullptr);
    ~user_bag();
    void show_role_info();//展示背包角色信息
    void show_weagon_info();//展示背包武器信息
    void get_uid(QString);//获取UID

private slots:
    void on_bag_return_clicked();

private:
    Ui::user_bag *ui;
    item_info * info;
    QString uid;//存放uid
};

#endif // USER_BAG_H

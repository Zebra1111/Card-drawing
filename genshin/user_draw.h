#ifndef USER_DRAW_H
#define USER_DRAW_H

#include <QWidget>
#include "user_info.h"
#include <QPainter>
#include <qsqlquery.h>
#include<qvariant.h>
#include <QSqlQuery>
#include <QMessageBox>
#include "user_bag.h"
#include "update_info.h"

namespace Ui {
class user_draw;
}

class user_draw : public QWidget
{
    Q_OBJECT

public:
    explicit user_draw(QWidget *parent = nullptr);
    ~user_draw();
    void get_info(user_info *);//获取数据
    //   void out_info();
    void changecycle(int x);
    int getcycle();
private slots:
    void on_once_clicked();

    void on_tentimes_clicked();

    void on_role_clicked();

    void on_weapon_clicked();

    void on_normal_clicked();

    void on_pushButton_clicked();

    void on_exit_clicked();

    void on_history_clicked();

    void on_bag_clicked();

    void on_check_clicked();

    void on_update_clicked();

private:
    Ui::user_draw *ui;
    user_info *info;
    int cycle_num = 0;
    QString path[10];
};

#endif // USER_DRAW_H

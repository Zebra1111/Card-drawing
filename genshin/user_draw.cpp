#include "user_draw.h"
#include "ui_user_draw.h"
#include "once_draw.h"
#include "tenth_draw.h"
#include"money.h"
#include<algorithm>
#include<map>
#include"history.h"
#include"cardpool.h"
user_draw::user_draw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_draw),info(nullptr)
{
    ui->setupUi(this);
    info = user_info::get_instance();
    ui->frame->setStyleSheet("#frame{border-image: url(:/image/background.jpg);}");
    ui->poolpic->setStyleSheet("border-image: url(:/image/background_cycle_0.jpg);");

}

user_draw::~user_draw()
{
    delete ui;
}

void user_draw::get_info(user_info * pass_info)
{
    info = pass_info;
    QSqlQuery sql;
    QString str = "select Treasure from user where UID =";
    QString str1 = info->out_user_uid();
    sql.exec(str + str1);
    int treature;
    while(sql.next())
        treature = sql.value(0).toInt();
    ui->label->setText(QString::number(treature));
    ui->name->setText(info->out_user_name());
}

//void user_draw::out_info()
//{
//    qDebug() << info->out_user_uid() << info->out_user_psd() << info->out_user_name() << info->out_user_cnt1() << info->out_user_cnt2() << info->out_user_treasure();
//}

void user_draw::on_once_clicked()
{
    once_draw one_pray;
    int treasure ,flag;
    QSqlQuery sql;
    sql.prepare("call Draw(:uid,:cycle,@result2);");
    sql.bindValue(":uid",info->out_user_uid());
    sql.bindValue(":cycle",this->getcycle());
    sql.exec();
    sql.exec("SELECT @result2");
    while(sql.next())
        flag = sql.value(0).toInt();
    if(!flag)
    {

        QMessageBox::warning(this, "错误", "原石数量不足");//警告
        return;
    }
    QString str1 = "select Treasure from user where UID = ";
    QString str2 = info->out_user_uid();
    sql.exec(str1 + str2);
    while(sql.next())
        treasure = sql.value(0).toInt();
    info->change_user_treasure(treasure);
    ui->label->setText(QString::number(info->out_user_treasure()));
    sql.exec("SELECT Order_num,Ob_no ,Ob_star FROM history ORDER BY Order_num DESC LIMIT 1");
    int a;
    QString str = ".jpg";
    while(sql.next())
        a = sql.value(1).toInt();
    path[0] = QString::number(a) + str;
    one_pray.get_path(path[0]);
    one_pray.exec();
}


void user_draw::on_tentimes_clicked()
{
    tenth_draw ten_pray;
    QSqlQuery sql;
    int treasure;
    QString str1 = "select Treasure from user where UID =";
    QString str2 = info->out_user_uid();
    sql.exec(str1 + str2);
    while(sql.next())
        treasure = sql.value(0).toInt();
    if(treasure < 1600)
    {

        QMessageBox::warning(this,"错误","原石数量不足");//警告
        return;
    }
    sql.prepare("call Draw(:uid,:cycle,@result);");
    sql.bindValue(":uid",info->out_user_uid());
    sql.bindValue(":cycle",this->getcycle());
    for(int i = 0 ; i < 10 ; i++)
        sql.exec();
     str1 = "select Treasure from user where UID =";//获得更新后的原石
     str2 = info->out_user_uid();
    sql.exec(str1 + str2);
    while(sql.next())
        treasure = sql.value(0).toInt();
    info->change_user_treasure(treasure);
    ui->label->setText(QString::number(info->out_user_treasure()));
    int t = 0;
    QPair<int,int> a[10];
    sql.exec("SELECT Order_num,Ob_no ,Ob_star FROM history ORDER BY Order_num DESC LIMIT 10");
    while(sql.next())
    {
        a[t].first = sql.value(2).toInt();
        a[t].second = sql.value(1).toInt();
        t++;
    }
    std::sort(a, a + 10, [](const QPair<int, int>& p1, const QPair<int, int>& p2) {
        return p1.first > p2.first;
    });
    QString str = ".jpg";
    for(int i = 0 ; i < 10 ; i++)
    {
        path[i] =  QString::number(a[i].second) + str;
    }
    ten_pray.get_path(path);
    ten_pray.exec();
}

int user_draw::getcycle()
{
    return cycle_num;
}
void user_draw::changecycle(int x)
{
    cycle_num = x;
    return;
}
void user_draw::on_role_clicked()
{
    this->changecycle(0);
    ui->poolpic->setStyleSheet("border-image: url(:/image/background_cycle_0.jpg);");//角色池背景待更改
}


void user_draw::on_weapon_clicked()
{
    this->changecycle(1);
    ui->poolpic->setStyleSheet("border-image: url(:/image/background_cycle_1.jpg);");//角色池背景待更改
}

void user_draw::on_normal_clicked()
{
    this->changecycle(2);
    ui->poolpic->setStyleSheet("border-image: url(:/image/background_cycle_2.png);");//角色池背景待更改
}


void user_draw::on_pushButton_clicked()
{
    money mon;
    mon.recharge(info->out_user_uid());
    mon.exec();
    QSqlQuery sql;
    QString str = "select Treasure from user where UID =";
    QString str1 = info->out_user_uid();
    sql.exec(str + str1);
    int treature;
    while(sql.next())
        treature = sql.value(0).toInt();
    ui->label->setText(QString::number(treature));
}



void user_draw::on_exit_clicked()
{
    exit(0);
}



void user_draw::on_history_clicked()
{
    history query;
    query.get_uid(info->out_user_uid());
    query.exec();
}


void user_draw::on_bag_clicked()
{
    user_bag dia_user_bag;//背包窗口
    dia_user_bag.get_uid(info->out_user_uid());
    dia_user_bag.exec();
}


void user_draw::on_check_clicked()
{
    cardpool query;
    query.show_all_role();
    query.show_all_weapon();
    query.show_all_normal();
    query.exec();
}


void user_draw::on_update_clicked()
{
    update_info dia_update_info;//调用修改信息界面
    dia_update_info.get_info(info->out_user_uid(), info->out_user_psd(), info->out_user_name());//信息传递
    dia_update_info.exec();
    info->load_info(info->out_user_uid());
    ui->name->setText(info->out_user_name());
}


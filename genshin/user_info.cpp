#include "user_info.h"

user_info::user_info()
{

}

user_info * user_info::ptr_user_infor = nullptr;//函数外进行初始化

void user_info::load_info(QString uid)
{
    user_uid = uid;
    QSqlQuery sql;
    sql.prepare("select * from user where UID = :uid");
    sql.bindValue(":uid", uid);
    sql.exec();
    while(sql.next())
    {
        user_psd = sql.value(1).toString();
        user_name = sql.value(2).toString();
        changzhu_cnt_4 = sql.value(3).toInt();
        changzhu_cnt_5 = sql.value(4).toInt();
        juese_cnt_4 = sql.value(5).toInt();
        juese_cnt_5 = sql.value(6).toInt();
        wuqi_cnt_4 = sql.value(7).toInt();
        wuqi_cnt_5 = sql.value(8).toInt();
        user_treasure = sql.value(9).toInt();
    }
}

QList<user_info> user_info::get_info_to_manage_user(QString uid)
{
    QList<user_info> list_info;
    user_info info;
    QSqlQuery sql;
    sql.prepare("select * from user where UID = :uid and UID != '123'");
    sql.bindValue(":uid", uid);
    sql.exec();
    while(sql.next())
    {
        info.user_uid = sql.value(0).toString();
        info.user_psd = sql.value(1).toString();
        info.user_name = sql.value(2).toString();
        info.changzhu_cnt_4 = sql.value(3).toInt();
        info.changzhu_cnt_5 = sql.value(4).toInt();
        info.juese_cnt_4 = sql.value(5).toInt();
        info.juese_cnt_5 = sql.value(6).toInt();
        info.wuqi_cnt_4 = sql.value(7).toInt();
        info.wuqi_cnt_5 = sql.value(8).toInt();
        info.user_treasure = sql.value(9).toInt();
        list_info.push_back(info);
    }
    return list_info;
}

QList<user_info> user_info::load_all_user_info()
{
    QList<user_info> l_user;
    user_info info;
    QSqlQuery sql;
    sql.exec("select * from user where UID != '123'");
    while(sql.next())
    {
        info.user_uid = sql.value(0).toString();
        info.user_psd = sql.value(1).toString();
        info.user_name = sql.value(2).toString();
        info.changzhu_cnt_4 = sql.value(3).toInt();
        info.changzhu_cnt_5 = sql.value(4).toInt();
        info.juese_cnt_4 = sql.value(5).toInt();
        info.juese_cnt_5 = sql.value(6).toInt();
        info.wuqi_cnt_4 = sql.value(7).toInt();
        info.wuqi_cnt_5 = sql.value(8).toInt();
        info.user_treasure = sql.value(9).toInt();
        l_user.push_back(info);
    }
    return l_user;
}

QString user_info::out_user_uid()
{
    return user_uid;
}

QString user_info::out_user_psd()
{
    return user_psd;
}

QString user_info::out_user_name()
{
    return user_name;
}

int user_info::out_changzhu_cnt_4()
{
    return changzhu_cnt_4;
}

int user_info::out_changzhu_cnt_5()
{
    return changzhu_cnt_5;
}

int user_info::out_juese_cnt_4()
{
    return juese_cnt_4;
}

int user_info::out_juese_cnt_5()
{
    return juese_cnt_5;
}

int user_info::out_wuqi_cnt_4()
{
    return wuqi_cnt_5;
}

int user_info::out_wuqi_cnt_5()
{
    return wuqi_cnt_5;
}

int user_info::out_user_treasure()
{
    return user_treasure;
}
void user_info::change_user_treasure(int x)
{
    user_treasure = x;
    return ;
}

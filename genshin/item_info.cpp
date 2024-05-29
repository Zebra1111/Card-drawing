#include "item_info.h"

item_info * item_info::ptr_item_infor = nullptr;

item_info::item_info()
{

}

QList<item_info> item_info::load_item_info(QString uid, int type)
{
    QList<item_info> list_info;//存放查找到的信息
    item_info info;
    QSqlQuery sql;
    if(!type)//角色类型值为0，武器为1，从数据库中查找信息
        sql.prepare("SELECT Ob_name,Ob_num,Ob_star FROM warehouse WHERE UID = :id and Ob_type = 0 ORDER BY Ob_star DESC;");
    else
        sql.prepare("SELECT Ob_name,Ob_num,Ob_star FROM warehouse WHERE UID = :id and Ob_type = 1 ORDER BY Ob_star DESC;");
    sql.bindValue(":id", uid);
    sql.exec();
    while(sql.next())
    {
        info.name = sql.value(0).toString();
        info.level = sql.value(2).toInt();
        info.num = sql.value(1).toInt();
        list_info.push_back(info);
    }
    return list_info;
}

QString item_info::out_name()
{
    return name;
}

int item_info::out_level()
{
    return level;
}

int item_info::out_num()
{
    return num;
}

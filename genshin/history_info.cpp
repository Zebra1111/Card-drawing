#include "history_info.h"
#include <QDateTime>
#include<QDebug>
history_info * history_info::ptr_history_info = nullptr;//函数外进行初始化
history_info::history_info()
{

}
QList<history_info> history_info::get_all_history(QString uid)
{
    QList<history_info> list_info;
    history_info info;
    QSqlQuery sql;
    sql.prepare("select Time,Ob_name,Ob_star,Ob_type from history where UID = :uid");
    sql.bindValue(":uid", uid);
    sql.exec();
    while(sql.next())
    {
        QDateTime datetime = sql.value(0).toDateTime();
        QString datetimeString = datetime.toString("yyyy-MM-dd hh:mm:ss");
        info.date = datetimeString;
        info.name = sql.value(1).toString();
        info.star = sql.value(2).toInt();
        info.type = sql.value(3).toInt();
        list_info.push_back(info);
    }
    return list_info;
}
QString history_info::get_date()
{
    return date;
}
QString history_info::get_name()
{
    return name;
}
int history_info::get_star()
{
    return star;
}
QString history_info::get_type()
{
    if(type == 0)
        return "角色";
    if(type == 1)
        return "武器";
    return "常驻";
}

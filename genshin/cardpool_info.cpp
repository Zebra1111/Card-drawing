#include "cardpool_info.h"
cardpool_info * cardpool_info::ptr_cardpool_info = nullptr;//函数外进行初始化
cardpool_info::cardpool_info()
{

}
QString cardpool_info::get_name()
{
    return name;
}
int cardpool_info::get_star()
{
    return star;
}
QString cardpool_info::get_type()
{
    if(type == 0)
        return "角色";
    return "武器";
}
QList<cardpool_info> cardpool_info::get_all_role()
{
    QList<cardpool_info> list_info;
    cardpool_info info;
    QSqlQuery sql;
    sql.exec("select Ob_name,Ob_star ,Ob_type from cardpool where Cycle = 0");
    while(sql.next())
    {
        info.name = sql.value(0).toString();
        info.star = sql.value(1).toInt();
        info.type = sql.value(2).toInt();
        list_info.push_back(info);
    }
    return list_info;
}
QList<cardpool_info> cardpool_info::get_all_weapon()
{
    QList<cardpool_info> list_info;
    cardpool_info info;
    QSqlQuery sql;
    sql.exec("select Ob_name,Ob_star ,Ob_type from cardpool where Cycle = 1");
    while(sql.next())
    {
        info.name = sql.value(0).toString();
        info.star = sql.value(1).toInt();
        info.type = sql.value(2).toInt();
        list_info.push_back(info);
    }
    return list_info;
}
QList<cardpool_info> cardpool_info::get_all_normal()
{
    QList<cardpool_info> list_info;
    cardpool_info info;
    QSqlQuery sql;
    sql.exec("select Ob_name,Ob_star ,Ob_type from cardpool where Cycle = 2");
    while(sql.next())
    {
        info.name = sql.value(0).toString();
        info.star = sql.value(1).toInt();
        info.type = sql.value(2).toInt();
        list_info.push_back(info);
    }
    return list_info;
}

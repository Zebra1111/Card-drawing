#ifndef ITEM_INFO_H
#define ITEM_INFO_H
#include<QString>
#include<QObject>
#include"qsqlquery.h"
#include"qvariant.h"

class item_info
{
public:
    item_info();
    static item_info *ptr_item_infor;
    static item_info *get_instance()
    {
        if(nullptr == ptr_item_infor)
            ptr_item_infor = new item_info;
        return ptr_item_infor;
    }
    QList<item_info> load_item_info(QString, int);//加载物品信息
    QString out_name();//返回物品名
    int out_level();//返回物品等级
    int out_num();//返回物品数量

private:
    QString name;//物品名
    int level;//物品等级
    int num;//物品数量
};

#endif // ITEM_INFO_H

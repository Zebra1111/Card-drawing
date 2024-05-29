#ifndef CARDPOOL_INFO_H
#define CARDPOOL_INFO_H


#include <QPainter>
#include <qsqlquery.h>
#include<qvariant.h>
#include <QSqlQuery>
#include<QString>
#include <QMessageBox>
class cardpool_info
{
public:
    cardpool_info();
    static cardpool_info *ptr_cardpool_info;
    static cardpool_info *get_instance()
    {
        if(nullptr == ptr_cardpool_info)
            ptr_cardpool_info = new cardpool_info;
        return ptr_cardpool_info;
    }
    int get_star();
    QString get_name();
    QString get_type();
    QList<cardpool_info> get_all_role();
    QList<cardpool_info> get_all_weapon();
    QList<cardpool_info> get_all_normal();
private:
    QString name;
    int star;
    int type;
};

#endif // CARDPOOL_INFO_H

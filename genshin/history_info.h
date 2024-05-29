#ifndef HISTORY_INFO_H
#define HISTORY_INFO_H
#include <QDialog>
#include <QPainter>
#include <qsqlquery.h>
#include<qvariant.h>
#include <QSqlQuery>
#include<QString>
#include <QMessageBox>
#include<QString>
class history_info
{
public:
    history_info();
    static history_info *ptr_history_info;
    static history_info *get_instance()
    {
        if(nullptr == ptr_history_info)
            ptr_history_info = new history_info;
        return ptr_history_info;
    }
    QList<history_info> get_all_history(QString uid);
    QString get_date();
    QString get_name();
    QString get_type();
    int get_star();
private:
    QString date;
    QString name;
    int star;
    int type;

};

#endif // HISTORY_INFO_H

#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include <QPainter>
#include <qsqlquery.h>
#include<qvariant.h>
#include <QSqlQuery>
#include<QString>
#include <QMessageBox>
#include"history_info.h"
namespace Ui {
class history;
}

class history : public QDialog
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();
    void get_uid(QString str);
    void show_all_user_history();
private:
    Ui::history *ui;
    QString uid;
    history_info *info;
};

#endif // HISTORY_H

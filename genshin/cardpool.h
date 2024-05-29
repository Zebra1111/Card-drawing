#ifndef CARDPOOL_H
#define CARDPOOL_H

#include <QDialog>
#include <QDialog>
#include <QPainter>
#include <qsqlquery.h>
#include<qvariant.h>
#include <QSqlQuery>
#include <QDebug>
#include<QString>
#include <QMessageBox>
#include"cardpool_info.h"
namespace Ui {
class cardpool;
}

class cardpool : public QDialog
{
    Q_OBJECT

public:
    explicit cardpool(QWidget *parent = nullptr);
    ~cardpool();
    void show_all_role();
    void show_all_weapon();
    void show_all_normal();
private:
    Ui::cardpool *ui;
    cardpool_info *info;
};

#endif // CARDPOOL_H

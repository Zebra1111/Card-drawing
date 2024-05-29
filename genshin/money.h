#ifndef MONEY_H
#define MONEY_H

#include <QDialog>
#include <QPainter>
#include <qsqlquery.h>
#include<qvariant.h>
#include <QSqlQuery>
#include<QString>
#include <QMessageBox>
namespace Ui {
class money;
}

class money : public QDialog
{
    Q_OBJECT

public:
    explicit money(QWidget *parent = nullptr);
    ~money();
    void recharge(QString uid);
private slots:
    void on_pushButton_clicked();

private:
    QString money_uid;
    Ui::money *ui;
};

#endif // MONEY_H

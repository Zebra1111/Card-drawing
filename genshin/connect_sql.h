#ifndef CONNECT_SQL_H
#define CONNECT_SQL_H

#include <QDialog>
#include <QSqlDatabase>
#include "QMessageBox"

namespace Ui {
class connect_sql;
}

class connect_sql : public QDialog
{
    Q_OBJECT

public:
    explicit connect_sql(QWidget *parent = nullptr);
    ~connect_sql();

private:
    Ui::connect_sql *ui;
};

#endif // CONNECT_SQL_H

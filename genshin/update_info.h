#ifndef UPDATE_INFO_H
#define UPDATE_INFO_H

#include <QDialog>
#include <qsqlquery.h>
#include <qvariant.h>
#include "QMessageBox"

namespace Ui {
class update_info;
}

class update_info : public QDialog
{
    Q_OBJECT

public:
    explicit update_info(QWidget *parent = nullptr);
    ~update_info();
    void get_info(QString, QString, QString);//获取选中用户的信息

private slots:
    void on_update_sure_clicked();//确认修改按钮

    void on_update_exit_clicked();//返回按钮

private:
    Ui::update_info *ui;
    QString uid;//选中用户的UID
    QString psd;//选中用户的密码
    QString name;//选中用户的昵称
};

#endif // UPDATE_INFO_H

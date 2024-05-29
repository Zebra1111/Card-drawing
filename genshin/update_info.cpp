#include "update_info.h"
#include "ui_update_info.h"

update_info::update_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update_info)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("#frame{background-color: rgb(255, 255, 255);}");
}

update_info::~update_info()
{
    delete ui;
}

void update_info::get_info(QString get_uid, QString get_psd, QString get_name)
{
    uid = get_uid;
    psd = get_psd;
    name = get_name;
    ui->update_psd->setText(psd);
    ui->update_name->setText(name);
}

void update_info::on_update_sure_clicked()
{
    QString update_psd;//修改后的密码
    QString update_name;//修改后的昵称
    QSqlQuery sql;
    update_psd = ui->update_psd->text();
    update_name = ui->update_name->text();
    sql.prepare("call update_user(:uid,:psd,:name,@result6)");//调用修改信息的存储过程
    sql.bindValue(":uid", uid);
    sql.bindValue(":psd", update_psd);
    sql.bindValue(":name", update_name);
    sql.exec();
    sql.exec("select @result6");
    int update_check = 0;//检查修改是否成功
    while(sql.next())
        update_check = sql.value(0).toInt();
    if(!update_check)
        QMessageBox::warning(this, "错误信息", "密码或用户名不能为空");
    else
    {
        QMessageBox::information(this, "信息", "修改成功！");
        this->close();
    }
}


void update_info::on_update_exit_clicked()
{
    this->close();
}


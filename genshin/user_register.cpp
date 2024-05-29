#include "user_register.h"
#include "ui_user_register.h"

user_register::user_register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_register)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("#frame{background-color: rgb(255, 255, 255);}");
}

user_register::~user_register()
{
    delete ui;
}

void user_register::on_register_exit_clicked()
{
    this->close();
}


void user_register::on_register_sure_clicked()
{
    QString insert_uid;//输入的UID
    QString insert_psd;//输入的密码
    QString insert_name;//输入的昵称
    QSqlQuery sql;//数据库对象
    int check_insert = 0;
    insert_uid = ui->uid_insert->text();//从输入框获得uid
    insert_psd = ui->psd_insert->text();//从输入框获得密码
    insert_name = ui->name_insert->text();//从输入框获得昵称
    sql.prepare("call register(:insert_uid,:insert_psd,:insert_name,@result_1);");
    sql.bindValue(":insert_uid", insert_uid);
    sql.bindValue(":insert_psd", insert_psd);
    sql.bindValue(":insert_name", insert_name);
    sql.exec();
    sql.exec("select @result_1");//检验插入数据是否成功
    while(sql.next())
        check_insert = sql.value(0).toInt();
    if(!check_insert)
        QMessageBox::warning(this, "插入失败", "UID为空或已存在");
    else
    {
        QMessageBox::information(this, "信息", "注册成功");
        this->close();
    }
}


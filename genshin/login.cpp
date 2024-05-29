#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
    ,info(nullptr)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("#frame{border-image: url(:/image/login_gate.jpg);}");//去除控件背景继承
    this->show();
    info = user_info::get_instance();
}

login::~login()
{
    delete ui;
}


void login::on_login_check_clicked()
{
    QString insert_uid;//从输入框获取uid
    QString insert_psd;//从输入框获取密码
    QSqlQuery sql;//数据库对象
    bool login_check = false;//登录是否成功
    insert_uid = ui->login_uid->text();
    insert_psd = ui->login_psd->text();
    sql.prepare("call User_login(:uid,:psd,@result);");//调用登录函数
    sql.bindValue(":uid",insert_uid);
    sql.bindValue(":psd",insert_psd);
    sql.exec();
    sql.exec("select @result");
    while(sql.next())
        login_check = sql.value(0).toInt();
    if(!login_check)//检验登录是否成功
        QMessageBox::warning(this, "登录失败", "UID不存在或密码错误！");
    else
    {
        QMessageBox::information(this, "登录成功", "欢迎您！");
        this->hide();
        info->load_info(insert_uid);//加载用户信息
        if(insert_uid != "123")//检验是否为管理员
        {
            this->draw.get_info(info);//将数据传给抽卡界面

            this->draw.show();
        }
        else
        {
            this->ad.get_info(info);//将数据传给管理员界面
            this->ad.show();
        }
    }
}


void login::on_login_register_clicked()
{
    user_register dia_user_register;//调用注册界面
    dia_user_register.exec();
}


void login::on_exit_clicked()
{
    exit(0);
}


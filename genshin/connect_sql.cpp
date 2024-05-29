#include "connect_sql.h"
#include "ui_connect_sql.h"

connect_sql::connect_sql(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connect_sql)
{
    ui->setupUi(this);
    this->show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    if (QSqlDatabase::drivers().isEmpty())//加载驱动
    {
        QMessageBox::warning(this, "错误信息", "驱动加载失败");
        this->close();
        exit(0);
    }
    db.setHostName("127.0.0.1");//主机号
    db.setPort(3306);//端口号
    db.setDatabaseName("mihayo");//数据库名
    db.setUserName("root");//数据库用户名
    db.setPassword("123456");//数据库密码
    bool flag = db.open();
    if(!flag)//查看数据库连接是否成功
    {
        QMessageBox::warning(this, "错误信息", "数据库连接失败");
        this->close();
        exit(0);
    }
    this->close();
}

connect_sql::~connect_sql()
{
    delete ui;
}

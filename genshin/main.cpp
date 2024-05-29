#include "login.h"
#include"connect_sql.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connect_sql con_sql;//连接数据库
    login login_widget;//调用登录界面
    return a.exec();
}

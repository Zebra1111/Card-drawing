#include "manager.h"
#include "ui_manager.h"

manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager), info(nullptr)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("#frame{border-image: url(:/image/manager_background.jpg);}");
    info = user_info::get_instance();
}

manager::~manager()
{
    delete ui;
}

void manager::get_info(user_info * pass_info)
{
    info = pass_info;
}

void manager::on_ManageUser_clicked()
{
    manage_user dia_manage_user;
    dia_manage_user.exec();
}

void manager::on_ManageExit_clicked()
{
    exit(0);
}


#include "user_bag.h"
#include "ui_user_bag.h"

user_bag::user_bag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_bag), info(nullptr)
{
    ui->setupUi(this);
    ui->role_widget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);//设置列宽
    ui->role_widget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->role_widget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->weapon_widget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->weapon_widget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->weapon_widget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->frame->setStyleSheet("#frame{background-color: rgb(255, 255, 255);}");
    ui->tabWidget->setStyleSheet("QTabWidget#tabWidget{background-color:rgb(245,245,245);}\
        QTabBar::tab{background-color:rgb(200,200,200);color:rgb(0, 0, 0);}\
        QTabBar::tab{width:120;height:35}\
        QTabBar::tab::selected{background-color: rgb(255, 255, 127);color:rgb(255, 170, 0);}");
    info = item_info::get_instance();
}

user_bag::~user_bag()
{
    delete ui;
}

void user_bag::show_role_info()
{
    QList<item_info> list_info;//存放查找到的数据
    int list_size;//数据的数量
    list_info = info->load_item_info(uid, 0);
    list_size = list_info.size();
    ui->role_widget->clearContents();
    ui->role_widget->setRowCount(list_size);
    for(int i=0; i<list_size; i++)
    {
        ui->role_widget->setItem(i, 0, new QTableWidgetItem(list_info[i].out_name()));
        ui->role_widget->item(i, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//居中
        ui->role_widget->setItem(i, 1, new QTableWidgetItem(QString::number(list_info[i].out_num())));
        ui->role_widget->item(i, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->role_widget->setItem(i, 2, new QTableWidgetItem(QString::number(list_info[i].out_level())));
        ui->role_widget->item(i, 2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

void user_bag::show_weagon_info()
{
    QList<item_info> list_info;
    int list_size;
    list_info = info->load_item_info(uid, 1);
    list_size = list_info.size();
    ui->weapon_widget->clearContents();
    ui->weapon_widget->setRowCount(list_size);
    for(int i=0; i<list_size; i++)
    {
        ui->weapon_widget->setItem(i, 0, new QTableWidgetItem(list_info[i].out_name()));
        ui->weapon_widget->item(i, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->weapon_widget->setItem(i, 1, new QTableWidgetItem(QString::number(list_info[i].out_num())));
        ui->weapon_widget->item(i, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->weapon_widget->setItem(i, 2, new QTableWidgetItem(QString::number(list_info[i].out_level())));
        ui->weapon_widget->item(i, 2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

void user_bag::get_uid(QString pass_uid)
{
    uid = pass_uid;
    show_role_info();
    show_weagon_info();
}
void user_bag::on_bag_return_clicked()
{
    this->close();
}


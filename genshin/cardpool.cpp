#include "cardpool.h"
#include "ui_cardpool.h"

cardpool::cardpool(QWidget *parent) :
    QDialog(parent),info(nullptr),
    ui(new Ui::cardpool)
{
    ui->setupUi(this);
    ui->weapon_table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);//设置列宽
    ui->weapon_table->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->weapon_table->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->role_table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);//设置列宽
    ui->role_table->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->role_table->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->normal_table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);//设置列宽
    ui->normal_table->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->normal_table->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tabWidget->setStyleSheet("QTabWidget#tabWidget{background-color:rgb(245,245,245);}\
        QTabBar::tab{background-color:rgb(200,200,200);color:rgb(0, 0, 0);}\
        QTabBar::tab{width:120;height:35}\
        QTabBar::tab::selected{background-color: rgb(255, 255, 127);color:rgb(255, 170, 0);}");
    info = cardpool_info::get_instance();
}
void cardpool::show_all_role()
{
    QList<cardpool_info> list_info;
    int list_size;
    list_info = info->get_all_role();
    list_size = list_info.size();
    ui->role_table->clearContents();
    ui->role_table->setRowCount(list_size);//设置行数
    for(int i=0; i<list_size; i++)//插入数据
    {
        ui->role_table->setItem(i, 0, new QTableWidgetItem(list_info[i].get_name()));
        ui->role_table->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        ui->role_table->setItem(i, 1, new QTableWidgetItem(list_info[i].get_type()));
        ui->role_table->item(i, 1)->setTextAlignment(Qt::AlignCenter);

        ui->role_table->setItem(i, 2, new QTableWidgetItem(QString::number(list_info[i].get_star())));
        ui->role_table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
}
void cardpool::show_all_weapon()
{
    QList<cardpool_info> list_info;
    int list_size;
    list_info = info->get_all_weapon();
    list_size = list_info.size();
    ui->weapon_table->clearContents();
    ui->weapon_table->setRowCount(list_size);//设置行数
    for(int i=0; i<list_size; i++)//插入数据
    {
        ui->weapon_table->setItem(i, 0, new QTableWidgetItem(list_info[i].get_name()));
        ui->weapon_table->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        ui->weapon_table->setItem(i, 1, new QTableWidgetItem(list_info[i].get_type()));
        ui->weapon_table->item(i, 1)->setTextAlignment(Qt::AlignCenter);

        ui->weapon_table->setItem(i, 2, new QTableWidgetItem(QString::number(list_info[i].get_star())));
        ui->weapon_table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
}
void cardpool::show_all_normal()
{
    QList<cardpool_info> list_info;
    int list_size;
    list_info = info->get_all_normal();
    list_size = list_info.size();
    ui->normal_table->clearContents();
    ui->normal_table->setRowCount(list_size);//设置行数
    for(int i=0; i<list_size; i++)//插入数据
    {
        ui->normal_table->setItem(i, 0, new QTableWidgetItem(list_info[i].get_name()));
        ui->normal_table->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        ui->normal_table->setItem(i, 1, new QTableWidgetItem(list_info[i].get_type()));
        ui->normal_table->item(i, 1)->setTextAlignment(Qt::AlignCenter);

        ui->normal_table->setItem(i, 2, new QTableWidgetItem(QString::number(list_info[i].get_star())));
        ui->normal_table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
}
cardpool::~cardpool()
{
    delete ui;
}

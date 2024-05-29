#include "history.h"
#include "ui_history.h"
#include<QDebug>
history::history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history),info(nullptr)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);//设置列宽
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    info = history_info::get_instance();
}
void history::get_uid(QString str)
{
    uid = str;
    show_all_user_history();
    return;
}
void history::show_all_user_history()
{
    QList<history_info> list_info;//存放所有用户信息
    int list_size;
    list_info = info->get_all_history(uid);//加载所有用户信息
    list_size = list_info.size();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(list_size);//设置行数
    for(int i=0; i<list_size; i++)//插入数据
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(list_info[i].get_date()));
        ui->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(list_info[i].get_name()));
        ui->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(list_info[i].get_star())));
        ui->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(list_info[i].get_type()));
        ui->tableWidget->item(i, 3)->setTextAlignment(Qt::AlignCenter);
    }
}

history::~history()
{
    delete ui;
}


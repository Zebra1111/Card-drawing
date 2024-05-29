#include "manage_user.h"
#include "ui_manage_user.h"

manage_user::manage_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_user), info(nullptr)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);//设置列宽
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(5,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(6,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(7,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(8,QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Stretch);
    ui->frame->setStyleSheet("#frame{border-image: url(:/image/manage_user_bg.png);}");
    info = user_info::get_instance();
    show_all_user_info();//展示用户信息
}

manage_user::~manage_user()
{
    delete ui;
}

void manage_user::on_manage_user_select_clicked()
{
    QList<user_info> list_info;//存放搜索用户的信息
    int list_size;
    QString uid;
    uid = ui->select_uid->text();
    if("" == uid)//搜索为空，展示所有信息
        show_all_user_info();
    else
    {
        list_info = info->get_info_to_manage_user(uid);//搜索所得用户信息
        list_size = list_info.size();
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(list_size);//设置行数
        for(int i=0; i<list_size; i++)//插入数据
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(list_info[i].out_user_uid()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(list_info[i].out_user_psd()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(list_info[i].out_user_name()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(list_info[i].out_changzhu_cnt_4())));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(list_info[i].out_changzhu_cnt_5())));
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(list_info[i].out_wuqi_cnt_4())));
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(list_info[i].out_wuqi_cnt_5())));
            ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(list_info[i].out_juese_cnt_4())));
            ui->tableWidget->setItem(i, 8, new QTableWidgetItem(QString::number(list_info[i].out_juese_cnt_5())));
            ui->tableWidget->setItem(i, 9, new QTableWidgetItem(QString::number(list_info[i].out_user_treasure())));
        }
    }
}


void manage_user::on_manage_user_update_clicked()
{
    int cur_row = -1;//选中行的行数
    cur_row = ui->tableWidget->currentRow();//获取选中行的行数
    if(cur_row >= 0)
    {
        QString uid;//选中行的UID
        QString psd;//选中行的密码
        QString name;//选中行的昵称
        uid = ui->tableWidget->item(cur_row, 0)->text();
        psd = ui->tableWidget->item(cur_row, 1)->text();
        name = ui->tableWidget->item(cur_row, 2)->text();
        update_info dia_update_info;//调用修改信息界面
        dia_update_info.get_info(uid, psd, name);//信息传递
        dia_update_info.exec();
    }
    show_all_user_info();//刷新界面
}


void manage_user::on_manage_user_delete_clicked()
{
    int cur_row = -1;//选中行的行数
    QSqlQuery sql;
    cur_row = ui->tableWidget->currentRow();//获取选中行的行数
    if(cur_row >= 0)
    {
        QString uid;
        uid = ui->tableWidget->item(cur_row, 0)->text();//获取选中行的UID
        sql.prepare("delete from user where UID=:uid");//调用删除函数
        sql.bindValue(":uid", uid);
        sql.exec();
    }
    show_all_user_info();//刷新界面
}


void manage_user::on_manage_user_return_clicked()
{
    this->hide();
}

void manage_user::show_all_user_info()
{
    QList<user_info> list_info;//存放所有用户信息
    int list_size;
    list_info = info->load_all_user_info();//加载所有用户信息
    list_size = list_info.size();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(list_size);//设置行数
    for(int i=0; i<list_size; i++)//插入数据
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(list_info[i].out_user_uid()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(list_info[i].out_user_psd()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(list_info[i].out_user_name()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(list_info[i].out_changzhu_cnt_4())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(list_info[i].out_changzhu_cnt_5())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(list_info[i].out_wuqi_cnt_4())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(list_info[i].out_wuqi_cnt_5())));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(list_info[i].out_juese_cnt_4())));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(QString::number(list_info[i].out_juese_cnt_5())));
        ui->tableWidget->setItem(i, 9, new QTableWidgetItem(QString::number(list_info[i].out_user_treasure())));
    }
}


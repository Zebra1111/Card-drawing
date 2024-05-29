#include "insert_info.h"
#include "ui_insert_info.h"

insert_info::insert_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_info)
{
    ui->setupUi(this);
}

insert_info::~insert_info()
{
    delete ui;
}

#include "insert_role.h"
#include "ui_insert_role.h"

insert_role::insert_role(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_role)
{
    ui->setupUi(this);
}

insert_role::~insert_role()
{
    delete ui;
}

#include "tenth_draw.h"
#include "ui_tenth_draw.h"

tenth_draw::tenth_draw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tenth_draw)
{
    ui->setupUi(this);
}
void tenth_draw::get_path(QString path[])
{
    QString str = "border-image: url(:/image/";
    QString str1 = ")";
    QString ans_path[10];
    for(int i = 0 ; i < 10 ; i++)
    {
        ans_path[i] = str + path[i] + str1;
    }
    ui->pray1->setStyleSheet(ans_path[0]);
    ui->pray2->setStyleSheet(ans_path[1]);
    ui->pray3->setStyleSheet(ans_path[2]);
    ui->pray4->setStyleSheet(ans_path[3]);
    ui->pray5->setStyleSheet(ans_path[4]);
    ui->pray6->setStyleSheet(ans_path[5]);
    ui->pray7->setStyleSheet(ans_path[6]);
    ui->pray8->setStyleSheet(ans_path[7]);
    ui->pray9->setStyleSheet(ans_path[8]);
    ui->pray10->setStyleSheet(ans_path[9]);
    this->show();
}
tenth_draw::~tenth_draw()
{
    delete ui;
}

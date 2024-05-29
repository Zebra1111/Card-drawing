#include "once_draw.h"
#include "ui_once_draw.h"
#include<QString>
once_draw::once_draw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::once_draw)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("border-image: url(:/image/background.jpg)");

}
//void once_draw::paintEvent(QPaintEvent* )
//{
//    QPainter painter(this);
//    QPixmap pix;
//    Qimage img;
//    pix.load(":/image/login_gate.jpg");
//    painter.drawPixmap(0,0,width(),height(),pix);
//}
void once_draw::get_path(QString path)
{
    QString str = "border-image: url(:/image/";
    QString str1 = ")";
    QString ans_path = str + path + str1;
    ui->pray->setStyleSheet(ans_path);
    this->show();
}
once_draw::~once_draw()
{
    delete ui;
}

#include "money.h"
#include "ui_money.h"

money::money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::money)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("#frame{background-color: rgb(255, 255, 255);}");
}
void money::recharge(QString uid)
{
    money_uid = uid;
    return;
}
money::~money()
{
    delete ui;
}

void money::on_pushButton_clicked()
{
    QSqlQuery sql;
    QString str = ui->lineEdit->text();  // 获取QLineEdit控件的文本内容
    int rmb = str.toInt();  // 将文本内容转换为整型数据
    if(rmb <= 0)
    {
        QMessageBox::warning(this,"错误","充值金额不合法");
        close();
        return;
    }
    sql.prepare("call Recharge(:id,:num,@result5);");
    sql.bindValue(":id",money_uid);
    sql.bindValue(":num",rmb);
    sql.exec();
    QMessageBox::warning(this,"微信支付","充值成功");
    close();
    return;
}


#ifndef TENTH_DRAW_H
#define TENTH_DRAW_H

#include <QDialog>
#include<QString>
namespace Ui {
class tenth_draw;
}

class tenth_draw : public QDialog
{
    Q_OBJECT

public:
    explicit tenth_draw(QWidget *parent = nullptr);
    void get_path(QString path[]);
    ~tenth_draw();

private:
    Ui::tenth_draw *ui;
};

#endif // TENTH_DRAW_H

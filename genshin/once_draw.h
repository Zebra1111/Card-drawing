#ifndef ONCE_DRAW_H
#define ONCE_DRAW_H
#include<QString>
#include <QDialog>


namespace Ui {
class once_draw;
}

class once_draw : public QDialog
{
    Q_OBJECT

public:
    explicit once_draw(QWidget *parent = nullptr);
    void get_path(QString path);
    ~once_draw();

private:
//    void painterEvent(QPaintEvent*);
    Ui::once_draw *ui;
};

#endif // ONCE_DRAW_H

#ifndef INSERT_INFO_H
#define INSERT_INFO_H

#include <QDialog>

namespace Ui {
class insert_info;
}

class insert_info : public QDialog
{
    Q_OBJECT

public:
    explicit insert_info(QWidget *parent = nullptr);
    ~insert_info();

private:
    Ui::insert_info *ui;
};

#endif // INSERT_INFO_H

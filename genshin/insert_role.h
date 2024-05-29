#ifndef INSERT_ROLE_H
#define INSERT_ROLE_H

#include <QDialog>

namespace Ui {
class insert_role;
}

class insert_role : public QDialog
{
    Q_OBJECT

public:
    explicit insert_role(QWidget *parent = nullptr);
    ~insert_role();

private:
    Ui::insert_role *ui;
};

#endif // INSERT_ROLE_H

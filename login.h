#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "headers.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();


private:
    Ui::Login *ui;
    QByteArray hashEncode(QString data);
};

#endif // LOGIN_H

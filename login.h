#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "headers.h"
#include "signup.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    bool loginflag = true;
    void messageBox(QString message);



private slots:
    void on_signUpBtn_clicked();

    void on_loginBtn_clicked();


signals:
    void Logined(QString currentUser);

private:
    Ui::Login *ui;
    QJsonObject loginObject;
    QByteArray hashEncode(QString data);

    QtMaterialSnackbar  *const m_snackbar;
};

#endif // LOGIN_H

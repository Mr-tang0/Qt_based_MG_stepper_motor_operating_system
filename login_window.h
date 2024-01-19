#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "headers.h"
#include "signup_window.h"

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
    QByteArray hashEncode(QString data);
    QJsonObject loginObject;

private slots:
    void on_signUpBtn_clicked();

    void on_loginBtn_clicked();


signals:
    void signUping();
    void Logined(QString currentUser);

private:
    Ui::Login *ui;



    QtMaterialSnackbar  *const m_snackbar;
};

#endif // LOGIN_H

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "headers.h"
namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();
    QtMaterialSnackbar  *const m_snackbar;

private:
    Ui::signup *ui;

signals:
    void signUpDone(QString userName,QString passWord);
private slots:
    void on_confirm_clicked();
};

#endif // SIGNUP_H

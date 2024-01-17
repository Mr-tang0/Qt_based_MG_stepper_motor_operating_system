#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_confirm_clicked()
{
    QString userName = ui->userName->text();
    QString passWord = ui->passWord_1->text();
    QString passWord2 = ui->passWord_2->text();

    if(userName=="" or passWord=="" or passWord2=="")
    {
        m_snackbar->addMessage("用户名或密码不能为空");
        return;
    }

    if(passWord!=passWord2)
    {
        m_snackbar->addMessage("两次密码输入不一致");
        return;
    }
    if(passWord.length()<=5)
    {
        m_snackbar->addMessage("密码不少于6位");
        return;
    }
    else
    {
        emit signUpDone(userName,passWord);
    }
}

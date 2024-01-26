#include "signup_window.h"
#include "ui_signup_window.h"
#include "mainwindow.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    m_snackbar(new QtMaterialSnackbar),
    ui(new Ui::signup)
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

    if(userName=="" || passWord=="" || passWord2=="")
    {
        m_snackbar->addMessage(emptyEdit[MainWindow::ChineseOrEnglish]);
        return;
    }

    if(passWord!=passWord2)
    {
        m_snackbar->addMessage(inconsistency[MainWindow::ChineseOrEnglish]);
        return;
    }
    if(passWord.length()<6)
    {
        m_snackbar->addMessage(shortPassword[MainWindow::ChineseOrEnglish]);
        return;
    }
    else
    {
        emit signUpDone(userName,passWord);
    }
}

#include "login_window.h"
#include "ui_login_window.h"
#include "mainwindow.h"

QString Login::currentName = "";

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    // m_snackbar->setBackgroundColor(QColor(150,150,150));
    // m_snackbar->setFont(QFont("幼圆"));

    QString rootPath  = QCoreApplication::applicationDirPath();
    QFile file(rootPath+"/users/users.users");

    if(!file.open(QIODevice::ReadOnly))
    {
        QJsonObject loginObject;
        QJsonDocument jsonDoc(loginObject);
        QString temp  = jsonDoc.toJson();
        file.open(QIODevice::WriteOnly);
        file.write(temp.toUtf8());
    }
    else
    {
        QByteArray jsonData = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        loginObject = jsonDoc.object();

    }
    file.close();


    ui->signUpBtn->setEnabled(false);

    if(loginObject[hashEncode("admin")].isNull())//管理员权限判断
    {
        ui->signUpBtn->setText("无权限注册");
        ui->loginBtn->setText("无权限登录");
        ui->loginBtn->setEnabled(false);
    }

}

Login::~Login()
{
    delete ui;
}

QByteArray Login::hashEncode(QString data)
{
    QByteArray temp = data.toUtf8();
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(temp);
    QByteArray result = hash.result();
    return result;
}


void Login::on_loginBtn_clicked()
{
    QString userName = ui->userName->text();
    QString passWord = ui->passWord->text();
    ui->passWord->clear();

    QString hashPassWord = hashEncode(passWord);
    QString hashUserName = hashEncode(userName);

    if(userName=="" || passWord=="")
    {
        qDebug()<<MainWindow::ChineseOrEnglish;
        m_snackbar->addMessage(emptyEdit[MainWindow::ChineseOrEnglish]);
        return;
    }
    if(hashPassWord==loginObject[hashUserName].toString())
    {

        m_snackbar->addMessage(logined[MainWindow::ChineseOrEnglish]);
        currentName = userName;

        if(userName=="admin")//管理员登录才可注册
        {
            ui->signUpBtn->setEnabled(true);
        }

        emit Logined(userName);
        return;
    }
    else m_snackbar->addMessage(unlogined[MainWindow::ChineseOrEnglish]);


}


void Login::on_signUpBtn_clicked()
{
    emit signUping();
}



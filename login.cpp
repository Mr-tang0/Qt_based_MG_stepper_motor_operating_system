#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

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

void Login::messageBox(QString message)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{"
                          "min-width: 200px;"
                          "min-height: 100px; "
                          "}");

    msgBox.setWindowTitle("提示");
    msgBox.setText(message);
    msgBox.exec();
}

void Login::on_loginBtn_clicked()
{


    QString userName = ui->userName->text();
    QString passWord = ui->passWord->text();

    QString hashPassWord = hashEncode(passWord);
    QString hashUserName = hashEncode(userName);

    if(userName=="" or passWord=="")
    {
        m_snackbar->addMessage(QString("请输入用户名或密码!"));
        return;
    }
    if(hashPassWord==loginObject[hashUserName].toString())
    {
        m_snackbar->addMessage(QString("登录成功!"));
        emit Logined(userName);
        return;
    }
    else
    {
        m_snackbar->addMessage(QString("用户名或密码错误!"));
    }

}


void Login::on_signUpBtn_clicked()
{

    signup *w = new signup;
    w->show();

    connect(w,&signup::signUpDone,[=](QString userName,QString passWord){
        QString rootPath  = QCoreApplication::applicationDirPath();
        QFile file(rootPath+"/users/users.users");

        QString hashPassWord = hashEncode(passWord);
        QString hashUserName = hashEncode(userName);
        if(!loginObject[hashUserName].isNull())
        {
            w->m_snackbar->addMessage("用户已存在");
        }
        else
        {
            w->close();
            //this->show();
            ui->userName->setText(userName);
            ui->passWord->clear();

            loginObject[hashUserName] = hashPassWord;
            QJsonDocument jsonDoc;
            jsonDoc.setObject(loginObject);
            QString temp  = jsonDoc.toJson();
            file.open(QIODevice::WriteOnly);
            file.write(temp.toUtf8());
            file.close();

            m_snackbar->addMessage("注册成功");

        }
    });
}



#include "login_window.h"
#include "ui_login_window.h"

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
        m_snackbar->addMessage(emptyEdit[ChineseOrEnglish]);
        return;
    }
    if(hashPassWord==loginObject[hashUserName].toString())
    {
        m_snackbar->addMessage(logined[ChineseOrEnglish]);
        emit Logined(userName);
        return;
    }
    else
    {
        m_snackbar->addMessage(unlogined[ChineseOrEnglish]);
    }

}


void Login::on_signUpBtn_clicked()
{
    emit signUping();
}



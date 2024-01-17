#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QString rootPath  = QCoreApplication::applicationDirPath();
    QFile file(rootPath+"/users/users.json");

    if(!file.open(QIODevice::ReadOnly))
    {
        QJsonObject object;
        QJsonDocument jsonDoc(object);
        QString temp  = jsonDoc.toJson();
        file.open(QIODevice::WriteOnly);
        file.write(temp.toUtf8());
    }
    else
    {
        QByteArray jsonData = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonObject loginObject = jsonDoc.object();

    }
    file.close();


    connect(ui->loginBtn,&QPushButton::clicked,[=](){
        QString userName = ui->userName->text();
        QString passWord = ui->passWord->text();
        qDebug()<<hashEncode(userName).toHex();
    });

    QByteArray temp = "3259690335";



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

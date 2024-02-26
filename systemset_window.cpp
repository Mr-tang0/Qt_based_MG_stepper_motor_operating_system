#include "systemset_window.h"
#include "ui_systemset_window.h"
#include "mainwindow.h"
#include "formfill.h"


systemSet::systemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systemSet),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));
    resetThis();

    connect(ui->language,&QComboBox::currentTextChanged,[=](){
        if(ui->language->currentText()=="中文")
        {
            MainWindow::ChineseOrEnglish = 0;
        }
        else
        {
            MainWindow::ChineseOrEnglish = 1;
        }

    });
}

systemSet::~systemSet()
{
    delete ui;
}

void systemSet::resetThis()
{
    QString rootPath  = QCoreApplication::applicationDirPath();
    QString systemFilePath = rootPath +"/users/log/systemsetlog.json";

    QFile systemFile(systemFilePath);
    try {
        systemFile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(systemFilePath);
        return;
    }

    QByteArray jsonData = systemFile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    systemFile.close();

    ui->filepath->setText(jsonObject["path"].toString());
    FormFill::orginalPath = ui->filepath->text();//默认位置

    ui->envColor->setCurrentText(jsonObject["color"].toString());
    if(jsonObject["language"].toString()=="ENG")
    {
        ui->language->setCurrentText("English");
    }
    else {
        ui->language->setCurrentText("中文");
    }


    if(jsonObject["smooth"].toString()=="open")
    {
        ui->smoothCurve->setCurrentText("开启");
    }
    else
    {
        ui->smoothCurve->setCurrentText("关闭");
    }


    ui->precision->setCurrentText(jsonObject["display"].toString());
    ui->buandrate->setCurrentText(jsonObject["buandrate"].toString());
    ui->motorAddress->setCurrentText(jsonObject["motorAddress"].toString());
    ui->weighAddress->setCurrentText(jsonObject["weighAddress"].toString());
    ui->limitAddress->setCurrentText(jsonObject["limitAddress"].toString());


}

void systemSet::on_openPath_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this,QStringLiteral("选择保存位置"));
    ui->filepath->setText(folderPath);
}


void systemSet::on_saveSet_clicked()
{
    FormFill::orginalPath = ui->filepath->text();//默认位置

    QString rootPath  = QCoreApplication::applicationDirPath();
    QString systemFilePath = rootPath +"/users/log/systemsetlog.json";

    QFile systemFile(systemFilePath);
    try {
        systemFile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(systemFilePath);
        return;
    }

    QByteArray jsonData = systemFile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    systemFile.close();

    try {
        systemFile.open(QIODevice::WriteOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(systemFilePath);
        return;
    }

    jsonObject["path"]=ui->filepath->text();
    QJsonDocument newDoc(jsonObject);

    QTextStream out(&systemFile);
    out<<newDoc.toJson(QJsonDocument::Indented);

    systemFile.close();


}


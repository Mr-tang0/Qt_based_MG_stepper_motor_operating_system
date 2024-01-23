#include "helper.h"
#include "ui_helper.h"

Helper::Helper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Helper)
{
    ui->setupUi(this);

    QString rootPath  = QCoreApplication::applicationDirPath();

    QFile txtFile(rootPath+"/log/helper.txt");
    txtFile.open(QIODevice::ReadOnly);
    QTextStream txt(&txtFile);
    txt.setCodec("UTF-8");
    QString contain = txt.readAll();
    txtFile.close();
    ui->textBrowser->setText(contain);

}

Helper::~Helper()
{
    delete ui;
}


#include "about_window.h"
#include "ui_about_window.h"

Qbout::Qbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qbout)
{
    ui->setupUi(this);

    QString rootPath  = QCoreApplication::applicationDirPath();

    QFile txtFile(rootPath+"/log/about.txt");
    txtFile.open(QIODevice::ReadOnly);
    QTextStream txt(&txtFile);
    txt.setCodec("UTF-8");
    QString contain = txt.readAll();
    txtFile.close();
    ui->textBrowser->setText(contain);
}

Qbout::~Qbout()
{
    delete ui;
}

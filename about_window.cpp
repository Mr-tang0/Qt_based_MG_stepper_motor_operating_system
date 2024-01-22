#include "about_window.h"
#include "ui_about_window.h"

Qbout::Qbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qbout)
{
    ui->setupUi(this);

    QFile txtFile("D:/appfile/QT/Qtcode/MG-motor/log/aboutme.txt");
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

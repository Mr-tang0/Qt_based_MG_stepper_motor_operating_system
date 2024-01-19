#include "qbout.h"
#include "ui_qbout.h"

Qbout::Qbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qbout)
{
    ui->setupUi(this);
}

Qbout::~Qbout()
{
    delete ui;
}

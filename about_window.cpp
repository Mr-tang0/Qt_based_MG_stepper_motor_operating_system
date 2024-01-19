#include "about_window.h"
#include "ui_about_window.h"

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

#include "maintestui.h"
#include "ui_maintestui.h"

mainTestUi::mainTestUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainTestUi)
{
    ui->setupUi(this);
}

mainTestUi::~mainTestUi()
{
    delete ui;
}

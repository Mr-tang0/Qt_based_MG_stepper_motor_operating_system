#include "hleper.h"
#include "ui_hleper.h"

Hleper::Hleper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hleper)
{
    ui->setupUi(this);
}

Hleper::~Hleper()
{
    delete ui;
}

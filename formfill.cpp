#include "formfill.h"
#include "ui_formfill.h"

FormFill::FormFill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFill)
{
    ui->setupUi(this);
}

FormFill::~FormFill()
{
    delete ui;
}

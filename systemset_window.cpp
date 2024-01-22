#include "systemset_window.h"
#include "ui_systemset_window.h"

systemSet::systemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systemSet),
    m_snackbar(new QtMaterialSnackbar)
{
    ui->setupUi(this);
    m_snackbar->setParent(this);
    m_snackbar->setBackgroundColor(QColor(150,150,150));
    m_snackbar->setFont(QFont("幼圆"));

    connect(ui->language,&QComboBox::currentTextChanged,[=](){
        if(ui->language->currentText()=="中文")
        {
            ChineseOrEnglish = 0;
        }
        else
        {
            ChineseOrEnglish = 1;
        }
        qDebug()<<"in"<<ChineseOrEnglish;
    });
}

systemSet::~systemSet()
{
    delete ui;
}




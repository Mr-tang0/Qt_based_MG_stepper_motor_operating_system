#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test = new mainUiTest();
    empty = new QWidget();
    login = new Login();
    helper = new Hleper();
    about = new Qbout();
    signUp = new signup();

    QVBoxLayout *layout = new QVBoxLayout;
    delete ui->widget->layout();

    layout->addWidget(test);
    layout->addWidget(empty);
    layout->addWidget(login);
    layout->addWidget(helper);
    layout->addWidget(about);
    layout->addWidget(signUp);

    test->hide();
    empty->hide();
    login->show();
    helper->hide();
    about->hide();
    signUp->hide();

    //ui->test->setEnabled(false);

    ui->widget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    test->hide();
    login->show();
    test->hide();
    helper->hide();
    about->hide();
    signUp->hide();
}

void MainWindow::on_test_clicked()
{
    test->hide();
    login->hide();
    test->show();
    helper->hide();
    about->hide();
    signUp->hide();

}

void MainWindow::on_help_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    helper->show();
    about->hide();
    signUp->hide();
}

void MainWindow::on_about_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    helper->hide();
    about->show();
    signUp->hide();

}

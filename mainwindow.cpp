#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_snackbar(new QtMaterialSnackbar),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    test = new mainUiTest();
    empty = new QWidget();
    login = new Login();
//    helper = new Helper();
    about = new Qbout();
    signUp = new signup();
    system = new systemSet();

    QVBoxLayout *layout = new QVBoxLayout;
    delete ui->widget->layout();

    layout->addWidget(test);
    layout->addWidget(empty);
    layout->addWidget(login);
    //layout->addWidget(helper);
    layout->addWidget(about);
    layout->addWidget(signUp);
    layout->addWidget(system);

    test->hide();
    empty->hide();
    login->show();
    //helper->hide();
    about->hide();
    signUp->hide();
    system->hide();

    ui->test->setEnabled(false);
    ui->systemSet->setEnabled(false);

    ui->widget->setLayout(layout);

    connect(login,SIGNAL(signUping()),this,SLOT(signUping()));

    portUi *portui = new portUi;

    connect(login,&Login::Logined,this,[=](QString userName)
    {
        portui->show();
        currentUserName = userName;
        ui->test->setEnabled(true);
        ui->systemSet->setEnabled(true);
    });
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
    //helper->hide();
    about->hide();
    signUp->hide();
    system->hide();

}

void MainWindow::on_test_clicked()
{
    test->hide();
    login->hide();
    test->show();
    helper->hide();
    about->hide();
    signUp->hide();
    system->hide();


}

void MainWindow::on_help_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    //helper->show();
    about->hide();
    signUp->hide();
    system->hide();
}

void MainWindow::on_about_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    helper->hide();
    about->show();
    signUp->hide();
    system->hide();
}

void MainWindow::signUping()
{
    test->hide();
    login->hide();
    test->hide();
    //helper->hide();
    about->hide();
    signUp->show();
    system->hide();


    connect(signUp,&signup::signUpDone,[=](QString userName,QString passWord){
        QString rootPath  = QCoreApplication::applicationDirPath();
        QFile file(rootPath+"/users/users.users");

        QString hashPassWord = login->hashEncode(passWord);
        QString hashUserName = login->hashEncode(userName);

        if(!login->loginObject[hashUserName].isNull())
        {
            signUp->m_snackbar->addMessage("用户已存在");
        }
        else
        {
            signUp->m_snackbar->addMessage("注册成功");
            delay(500);

            signUp->hide();
            login->show();

            findChild<QLineEdit*>("userName")->setText(userName);
            findChild<QLineEdit*>("passWord")->clear();

            login->loginObject[hashUserName] = hashPassWord;
            QJsonDocument jsonDoc;
            jsonDoc.setObject(login->loginObject);
            QString temp  = jsonDoc.toJson();
            file.open(QIODevice::WriteOnly);
            file.write(temp.toUtf8());
            file.close();
        }


    });




    //    signup *w = new signup;
    //    w->show();

    //    connect(w,&signup::signUpDone,[=](QString userName,QString passWord){
    //        QString rootPath  = QCoreApplication::applicationDirPath();
    //        QFile file(rootPath+"/users/users.users");

    //        QString hashPassWord = hashEncode(passWord);
    //        QString hashUserName = hashEncode(userName);
    //        if(!loginObject[hashUserName].isNull())
    //        {
    //            w->m_snackbar->addMessage("用户已存在");
    //        }
    //        else
    //        {
    //            w->close();
    //            //this->show();
    //            ui->userName->setText(userName);
    //            ui->passWord->clear();

    //            loginObject[hashUserName] = hashPassWord;
    //            QJsonDocument jsonDoc;
    //            jsonDoc.setObject(loginObject);
    //            QString temp  = jsonDoc.toJson();
    //            file.open(QIODevice::WriteOnly);
    //            file.write(temp.toUtf8());
    //            file.close();

    //            m_snackbar->addMessage("注册成功");

    //        }
    //    });
}

void MainWindow::on_systemSet_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    //helper->hide();
    about->hide();
    signUp->hide();
    system->show();
}

void MainWindow::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();
}

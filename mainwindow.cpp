#include "mainwindow.h"
#include "ui_mainwindow.h"

//mainUiTest *MainWindow::test = new mainUiTest();

int MainWindow::ChineseOrEnglish = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_snackbar(new QtMaterialSnackbar),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadMotorAndWeigh();//导入默认电机称重文件

    ui->appVersion->setText("3.1.0.240129");

    ui->login->setForegroundColor(QColor(140, 140, 255));
    ui->test->setForegroundColor(QColor(140, 140, 255));
    ui->systemSet->setForegroundColor(QColor(140, 140, 255));
    ui->about->setForegroundColor(QColor(140, 140, 255));
    ui->help->setForegroundColor(QColor(140, 140, 255));



    test = new mainUiTest();

    empty = new QWidget();
    login = new Login();
    helper = new Helper();
    about = new Qbout();
    signUp = new signup();
    formfill = new FormFill();
    system = new systemSet();

    QVBoxLayout *layout = new QVBoxLayout;
    delete ui->widget->layout();

    layout->addWidget(test);
    layout->addWidget(empty);
    layout->addWidget(login);
    layout->addWidget(helper);
    layout->addWidget(about);
    layout->addWidget(signUp);
    layout->addWidget(formfill);
    layout->addWidget(system);

    test->hide();
    empty->hide();
    login->show();
    about->hide();
    signUp->hide();
    formfill->hide();
    system->hide();
    helper->hide();

    // ui->test->setEnabled(false);
    // ui->systemSet->setEnabled(false);

    ui->widget->setLayout(layout);

    //查询登录若有注册要求则跳注册
    connect(login,SIGNAL(signUping()),this,SLOT(signUping()));


    //登录成功跳转表单设置，同时开权限试验
    connect(login,&Login::Logined,this,[=](QString userName)
    {
        login->hide();
        ui->label->setText(userName);
        currentUserName = userName;
        ui->label->setText(currentUserName);
        ui->test->setEnabled(true);
        ui->systemSet->setEnabled(true);
        formfill->show();
    });


    //增加试验表单
    connect(formfill,&FormFill::saveSet,[=](QString rootPath){
        formfill->saveLabel(rootPath);
        delay(800);
        formfill->hide();
        test->resetThis();
        test->show();
    });

    //取消增加试验
    connect(formfill,&FormFill::cancelSet,[=](){on_test_clicked();});

    //新建试验
    connect(test,&mainUiTest::newTest,[=](){
        test->hide();
        formfill->resetThis();
        formfill->show();
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
    helper->hide();
    about->hide();
    signUp->hide();
    formfill->hide();
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
    formfill->hide();
    system->hide();

}

void MainWindow::on_help_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    helper->show();
    about->hide();
    signUp->hide();
    formfill->hide();
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
    formfill->hide();
    system->hide();
}

void MainWindow::on_systemSet_clicked()
{
    test->hide();
    login->hide();
    test->hide();
    helper->hide();
    about->hide();
    signUp->hide();
    formfill->hide();
    system->show();
}


void MainWindow::loadMotorAndWeigh()
{
    QString rootPath  = QCoreApplication::applicationDirPath();
    QString motorAndWeighFilePath = rootPath +"/users/log/motorandweighlog.json";

    QFile motorfile(motorAndWeighFilePath);
    try {
        motorfile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(motorAndWeighFilePath);
        return;
    }

    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    motorfile.close();

    motorDetails motordetail;
    motordetail=
        {
            jsonObject["motorAdress"].toString().toInt(),      //motorID
            jsonObject["speed"].toString().toDouble(),         //motorspeed
            jsonObject["maxSpeed"].toString().toDouble(),      //maxSpeed
            jsonObject["length"].toString().toDouble(),        //length
            jsonObject["maxLength"].toString().toDouble(),     //maxLength
            jsonObject["cycle"].toString().toDouble(),         //cycle
            jsonObject["picth"].toString().toDouble(),         //picth

            jsonObject["currentAngle"].toString().toDouble(),  //currentAngle
            jsonObject["zero"].toString().toDouble(),//约定0点
            jsonObject["Backlash"].toString().toDouble()//背隙补偿值

        };

   mainUiTest::myMotor->detail = motordetail;

    weighDetails weighdetail;
        weighdetail =
        {
            jsonObject["weighID"].toString().toInt(),          //weighID
            jsonObject["force"].toString().toDouble(),         //force
            jsonObject["maxForce"].toString().toDouble(),      //maxForce
            jsonObject["currentWeigth"].toString().toDouble() //currentWeigth
        };
    mainUiTest::myWeigh->detail = weighdetail;

}

void MainWindow::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();
}

void MainWindow::signUping()
{
    test->hide();
    login->hide();
    test->hide();
    helper->hide();
    about->hide();
    signUp->show();
    formfill->hide();
    system->hide();


    connect(signUp,&signup::signUpDone,[=](QString userName,QString passWord){
        QString rootPath  = QCoreApplication::applicationDirPath();
        QFile file(rootPath+"/users/users.users");

        QString hashPassWord = login->hashEncode(passWord);
        QString hashUserName = login->hashEncode(userName);

        if(!login->loginObject[hashUserName].isNull())
        {
            signUp->m_snackbar->addMessage("用户已存在!");
        }
        else
        {
            signUp->m_snackbar->addMessage("注册成功!");
            delay(500);

            signUp->hide();
            login->show();

            findChild<QLineEdit*>("userName")->setText(userName);
            findChild<QLineEdit*>("passWord")->clear();

            login->loginObject[hashUserName] = hashPassWord;
            // login->loginObject[]

            QJsonDocument jsonDoc;
            jsonDoc.setObject(login->loginObject);
            QString temp  = jsonDoc.toJson();
            file.open(QIODevice::WriteOnly);
            file.write(temp.toUtf8());
            file.close();
        }

    });

}

#include "test_window.h"
#include "ui_test_window.h"
#include "mainwindow.h"

mainUiTest::mainUiTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUiTest)
{
    ui->setupUi(this);

    QThread *mythread = new QThread;
    newworker->moveToThread(mythread);//worker进入子线程，有关于收发的函数均在子线程中执行
    newworker->openReseiveChannal();//开接收

    initSystem();


    startTime = QTime::currentTime();




    //测试

//    QTimer *timer = new QTimer;

//    static int i =1;

//    connect(timer,&QTimer::timeout,[=](){
//        QPointF data = pointTraslater(zero,QPointF(i, i));
//        datas<<data;
//        i+=1;
//        if(i>=800)timer->stop();
//        pathNormal.moveTo(datas.at(0));
//        for (int j = 0; j < datas.size(); ++j) {
//            pathNormal.lineTo(datas.at(j));
//        }
//        update();
//    });

//    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
//        timer->start(10);
//    });

}

mainUiTest::~mainUiTest()
{
    delete ui;
}

void mainUiTest::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(1, -1);

    int windowWidth = this->width();
    int windowHeight = this->height();
    zero  = QPointF(-windowWidth/2+50,-windowHeight/2+50);
    //绘制画布

    frameWidth = this->width()-ui->verticalLayout_5->geometry().width()-100;
    frameHeight =ui->horizontalLayout_4->geometry().height()-50;

    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);

    QRectF rectangle(zero,pointTraslater(zero,QPointF(frameWidth,frameHeight)));
    painter.drawRect(rectangle);

    //画原点
    painter.setBrush(Qt::black);
    painter.drawEllipse(zero, 3, 3);

    //画线
    painter.setPen(Qt::white);
    painter.setBrush(Qt::NoBrush);
    painter.drawPath(pathNormal);

}

QPointF mainUiTest::pointTraslater(QPointF zero,QPointF point)
{
    QPointF traslaterPoint = zero+point;

    return traslaterPoint;
}


void mainUiTest::on_startTest_clicked()
{
     myMotor->writePram();
}


void mainUiTest::on_newTest_clicked()
{
    emit newTest();
}

//开始测试，读电机设置，称重模块设置，测试参数（计算运动参数）
void mainUiTest::on_saveTest_clicked()
{

//    startTestFlag
}

void mainUiTest::on_stopTest_clicked()
{
    myMotor->stopMove();
}

void mainUiTest::on_emergency_clicked()
{
    myMotor->stopMove();
}

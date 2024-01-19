#include "mainuitest.h"
#include "ui_mainuitest.h"


mainUiTest::mainUiTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUiTest)
{
    ui->setupUi(this);

    //O点确认
//    int windowWidth = this->width();
//    int windowHeight = this->height();

//    zero  = QPointF(-windowWidth/2+50,-windowHeight/2+50);

    qDebug()<<zero;

    srand(QDateTime::currentDateTime().toMSecsSinceEpoch());


//    //这里用计时器来代替传感器发出的信号，数据也在上方添加完毕

    QTimer *timer = new QTimer;

    static int i =1;

    connect(timer,&QTimer::timeout,[=](){
        QPointF data = pointTraslater(zero,QPointF(i, abs(cos(i)*6/tan(i)+sin(i)*5+sin(i)*5*sin(i*5))));
        datas<<data;
        i+=1;
        if(i>=800)timer->stop();
        pathNormal.moveTo(datas.at(0));
        for (int j = 0; j < datas.size(); ++j) {
            pathNormal.lineTo(datas.at(j));
        }
        update();
    });

    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
        timer->start(10);
    });

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
    painter.drawEllipse(zero, 5, 5);

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

void mainUiTest::on_pushButton_8_clicked()
{

//    pathNormal.moveTo(datas.at(0));
//    for (int i = 0; i < datas.size(); ++i) {
//        pathNormal.lineTo(datas.at(i));
//    }
//    update();
}

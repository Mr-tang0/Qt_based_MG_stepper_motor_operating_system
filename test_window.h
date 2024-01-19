#ifndef MAINUITEST_H
#define MAINUITEST_H

#include <QWidget>
#include"headers.h"

#include"weigh.h"
#include"motor.h"
#include"worker.h"

namespace Ui {
class mainUiTest;
}

class mainUiTest : public QWidget
{
    Q_OBJECT

public:

    explicit mainUiTest(QWidget *parent = nullptr);
    ~mainUiTest();

    void paintEvent(QPaintEvent *event);//重写虚函数
    QPointF pointTraslater(QPointF zero,QPointF point);

    void delay(int time);
    void buttonTwinkling(QString btnName, QString color, bool flag);
    void saveJson(motor* givenMotor,QString filePath);
    void loadMotorDetails(QString filePath);
    void loadWeighDetails(QString filePath);

    void initSystem();
    void refreshUi();

    void saveMotor(QString filePath);
    void saveWeigh(QString filePath,bool clear);

    static QSerialPort *myPort;
    static Worker *newworker;

    static motor* myMotor;

    static weigh* myWeigh;

    static materialDetails *material;

    QTime startTime;

    QTimer* twinker =new QTimer;

private slots:


    void on_startTest_clicked();

private:
    QPointF zero;
    int frameWidth,frameHeight;
    Ui::mainUiTest *ui;
    QVector<QPointF> datas;
    QPainterPath pathNormal;

};

#endif // MAINUITEST_H

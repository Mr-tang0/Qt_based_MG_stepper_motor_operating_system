#ifndef MAINUITEST_H
#define MAINUITEST_H

#include <QWidget>
#include"headers.h"

#include"weigh.h"
#include"motor.h"
#include"worker.h"
#include "decodethread.h"

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
    void drawer(double x,double y);

    void saveMotor(QString filePath);
    void saveWeigh(QString filePath,bool clear);
    void resetClass();

    static QSerialPort *myPort;

    static Worker *sendWork;
    static decodeThread *decodeWork;

    static motor* myMotor;

    static weigh* myWeigh;

    static materialDetails *material;

    static QList<QStringList> testLog;//这是电机记录的位移和拉力模块记录的数据,每个QStringList是一对一的关系；

    static int sampleRate;

    QTimer* twinker =new QTimer;

private slots:

    void on_startTest_clicked();

    void on_newTest_clicked();

    void on_saveTest_clicked();

    void on_stopTest_clicked();

    void on_emergency_clicked();

    void on_clearTest_clicked();

signals:
    void newTest();

private:
    Ui::mainUiTest *ui;
    QtMaterialSnackbar  *const m_snackbar;

    QPointF zero;

    int frameWidth,frameHeight;

    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
    QValueAxis *axisY = new QValueAxis();
    QValueAxis *axisX = new QValueAxis();

    QVector<QPointF> datas;
    QVector<QPointF> DATA;

    QPainterPath pathNormal;

    void recodeTest(QString filePath);
    void mageDrawing();

    QTimer *startTimer = new QTimer;
    QTime startTime;

    QString filePath;


};

#endif // MAINUITEST_H

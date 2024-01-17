#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"headers.h"

#include"weigh.h"
#include"motor.h"
#include"worker.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void delay(int time);
    void buttonTwinkling(QString btnName, QString color, bool flag);
    void saveJson(QList<motor*> MotorList,QString filePath);
    void loadMotorDetails(QString filePath);
    void loadWeighDetails(QString filePath);

    void initSystem();
    void refreshUi();

    void saveMotor(int index,QString filePath);
    void saveWeigh(QString filePath,bool clear);

    static QSerialPort *myPort;
    static Worker *newworker;
    static QList<motor*> myMotorList;
    static weigh* myweigh;

    QTimer* twinker =new QTimer;



private slots:


    void on_changeWeigh_clicked();

    void on_refreshWeigh_clicked();

    void on_saveWeight_clicked();

    void on_weighShelling_clicked();

    void on_clearWeighLog_clicked();

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H

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
    void initSystem();
    void refreshUi();


    static QSerialPort *myPort;
    static Worker *newworker;
    static QList<motor*> myMotorList;

    QTimer *twinker = new QTimer;



private slots:


private:
    Ui::Widget *ui;
};



#endif // WIDGET_H

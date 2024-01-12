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

    void findAvailablePort();
    bool connectSerialPort(int baundRate,QString portName);
    void delay(int time);


    static QSerialPort *myPort;
    static Worker *newworker;




private:
    Ui::Widget *ui;
};



#endif // WIDGET_H

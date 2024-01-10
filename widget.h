#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"weigh.h"
#include"headers.h"




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


    static QSerialPort *myPort;
    const weigh *Weigh = new weigh();



private:
    Ui::Widget *ui;
};



#endif // WIDGET_H

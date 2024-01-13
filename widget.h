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
    void buttonTwinkling(QString btnName, bool flag);
    void saveJson(motorDetails &motordetail,QString filePath);
    void loadMotorDetails(QList<motorDetails> &loadmotordetail,QString filePath);


    static QSerialPort *myPort;
    static Worker *newworker;

    QTimer *twinker = new QTimer;


    Ui::Widget *ui;
private slots:
    void on_pushButton_clicked();

private:

};



#endif // WIDGET_H

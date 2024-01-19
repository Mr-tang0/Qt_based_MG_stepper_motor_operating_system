#ifndef MAINUITEST_H
#define MAINUITEST_H

#include <QWidget>
#include"headers.h"


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

private slots:
    void on_pushButton_8_clicked();

private:
    QPointF zero;
    int frameWidth,frameHeight;
    Ui::mainUiTest *ui;
    QVector<QPointF> datas;
    QPainterPath pathNormal;

};

#endif // MAINUITEST_H

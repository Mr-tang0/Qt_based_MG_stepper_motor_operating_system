#ifndef MAINTESTUI_H
#define MAINTESTUI_H

#include <QWidget>

namespace Ui {
class mainTestUi;
}

class mainTestUi : public QWidget
{
    Q_OBJECT

public:
    explicit mainTestUi(QWidget *parent = nullptr);
    ~mainTestUi();

private:
    Ui::mainTestUi *ui;
};

#endif // MAINTESTUI_H

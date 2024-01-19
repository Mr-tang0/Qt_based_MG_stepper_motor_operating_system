#ifndef QBOUT_H
#define QBOUT_H

#include <QWidget>

namespace Ui {
class Qbout;
}

class Qbout : public QWidget
{
    Q_OBJECT

public:
    explicit Qbout(QWidget *parent = nullptr);
    ~Qbout();

private:
    Ui::Qbout *ui;
};

#endif // QBOUT_H

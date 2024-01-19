#ifndef HLEPER_H
#define HLEPER_H

#include <QWidget>

namespace Ui {
class Hleper;
}

class Hleper : public QWidget
{
    Q_OBJECT

public:
    explicit Hleper(QWidget *parent = nullptr);
    ~Hleper();

private:
    Ui::Hleper *ui;
};

#endif // HLEPER_H

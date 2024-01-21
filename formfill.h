#ifndef FORMFILL_H
#define FORMFILL_H

#include <QWidget>

namespace Ui {
class FormFill;
}

class FormFill : public QWidget
{
    Q_OBJECT

public:
    explicit FormFill(QWidget *parent = nullptr);
    ~FormFill();

private:
    Ui::FormFill *ui;
};

#endif // FORMFILL_H

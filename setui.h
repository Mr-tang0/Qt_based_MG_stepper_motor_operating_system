#ifndef SETUI_H
#define SETUI_H

#include <QWidget>

namespace Ui {
class setui;
}

class setui : public QWidget
{
    Q_OBJECT

public:
    explicit setui(QWidget *parent = nullptr);
    ~setui();

private:
    Ui::setui *ui;
};

#endif // SETUI_H

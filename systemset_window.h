#ifndef SYSTEMSET_H
#define SYSTEMSET_H

#include <QWidget>
#include "headers.h"


namespace Ui {
class systemSet;
}

class systemSet : public QWidget
{
    Q_OBJECT

public:
    explicit systemSet(QWidget *parent = nullptr);
    ~systemSet();


private slots:

signals:


protected:

private:
    Ui::systemSet *ui;
    QtMaterialSnackbar  *const m_snackbar;


};

#endif // SYSTEMSET_H

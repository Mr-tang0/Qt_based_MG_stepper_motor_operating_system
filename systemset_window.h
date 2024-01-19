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

    void saveLabel(QString filePath);
    void saveCsvFile(QString filePath,QList<QStringList> data);

private slots:
    void on_submitBtn_clicked();
    void freshPort();

private:
    Ui::systemSet *ui;
    QtMaterialSnackbar  *const m_snackbar;
    QButtonGroup *group;
};

#endif // SYSTEMSET_H

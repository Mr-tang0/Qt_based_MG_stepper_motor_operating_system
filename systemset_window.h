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

    void findAvailablePort();

private slots:
    void on_submitBtn_clicked();

    void on_portRefresh_clicked();

    bool on_portConnect_clicked();

    void on_cancelBtn_clicked();

signals:
    void saveSet(QString rootPath);
    void cancelSet();
    void thisShow();

protected:
    void showEvent(QShowEvent*event)
    {
        emit thisShow();
        QWidget::showEvent(event);
    }
private:
    Ui::systemSet *ui;
    QtMaterialSnackbar  *const m_snackbar;
    QButtonGroup *group;

    QString showTime;
    static QString rootPath;
};

#endif // SYSTEMSET_H

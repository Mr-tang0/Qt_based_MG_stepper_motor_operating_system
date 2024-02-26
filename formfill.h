#ifndef FORMFILL_H
#define FORMFILL_H

#include <QWidget>
#include "headers.h"


namespace Ui {
class FormFill;
}

class FormFill : public QWidget
{
    Q_OBJECT

public:
    explicit FormFill(QWidget *parent = nullptr);
    ~FormFill();

    void saveLabel(QString filePath);
    void saveCsvFile(QString filePath,QList<QStringList> data);

    void findAvailablePort();
    void resetThis();

    static QString rootPath;
    static QString orginalPath;

    static void setRootPath(const QString &newRootPath);

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
    Ui::FormFill *ui;
    QtMaterialSnackbar  *const m_snackbar;
    QString showTime;
    QString currentName = "";

};

#endif // FORMFILL_H

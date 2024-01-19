#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headers.h"
#include "mainuitest.h"

#include "login.h"
#include "signup.h"
#include "hleper.h"
#include "qbout.h"
#include "signup.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *test,*empty,*login,*helper,*about,*signUp;


private slots:
    void on_login_clicked();

    void on_test_clicked();

    void on_help_clicked();

    void on_about_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

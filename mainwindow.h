#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headers.h"
#include "test_window.h"

#include "login_window.h"
#include "signup_window.h"

#include "about_window.h"
#include "signup_window.h"
#include "systemset_window.h"
#include "portui_window.h"
#include "formfill.h"
#include "helper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QWidget *empty;//初始化各个界面


    Login *login;
    signup *signUp;
    FormFill *formfill;
    Qbout *about;
    mainUiTest *test;
    systemSet *system;
    Helper *helper;

    void delay(int delayTime);


private slots:

    void on_login_clicked();

    void on_test_clicked();

    void on_help_clicked();

    void on_about_clicked();

    void signUping();

    void on_systemSet_clicked();


private:
    QtMaterialSnackbar  *const m_snackbar;
    Ui::MainWindow *ui;
    QString currentUserName;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QtDebug>
#include <QMessageBox>
#include <QValidator>
#include <cstring>
#include <QIcon>
#include <QDebug>
#include <algorithm>
#include "graphwindow.h"
#include "creditwindow.h"
 #include "depozit.h"
#include <QVector>

#ifdef __cplusplus
extern "C" {
#endif
    #include "calc.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QRegularExpressionValidator *val_form = new QRegularExpressionValidator(QRegularExpression("^([-]?\\d*[.]?\\d*|[+-/*^%]?|[x]|[(]|([)][+-/*^%]?)|sin[(]|cos[(]|tan[(]|sqrt[(]|asin[(]|acos[(]|atan[(]|log[(]|ln[(]){0,}$"), 0);
//    QRegularExpressionValidator *val_double = new QRegularExpressionValidator(QRegularExpression("[-]?\\d*[.]?\\d*"), 0);



private slots:

    void init();

    void on_mod_clicked();

    void on_equals_clicked();

    void on_del_clicked();

    void on_AC_clicked();

    void on_graph_clicked();

    void on_credit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

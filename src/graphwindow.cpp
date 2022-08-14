#include "graphwindow.h"
#include "ui_graphwindow.h"
//#include "mainwindow.h"

GraphWindow::GraphWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

}

GraphWindow::~GraphWindow()
{
    delete ui;
}

void GraphWindow::on_button_clicked()
{
    h = 0.1;
    xBegin = ui->domain_x_begin->text().toDouble();
    xEnd = ui->domain_x_end->text().toDouble() + h;
    yBegin = ui->domain_y_begin->text().toDouble();
    yEnd = ui->domain_y_end->text().toDouble();

    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(yBegin, yEnd);

//    N = (xEnd - xBegin)/h + 2;

    std::string exp_string = ui->expression->text().toUtf8().data();
    if (std::count(exp_string.begin(), exp_string.end(), '(') == std::count(exp_string.begin(), exp_string.end(), ')')) {
        int flag = 0;
        const char *exp_tmp = exp_string.c_str();
        char *exp = new char[strlen(exp_tmp) + 1];
        strlcpy(exp, exp_tmp, strlen(exp_tmp)+1);

        for (X = xBegin; X <= xEnd; X += h) {
            x.push_back(X);
            double X_tmp = from_infix_to_postfix(exp, X);
            if (X_tmp == INFINITY || X_tmp != X_tmp) {
                ui->expression->setText("Такое я не нарисую :(");
                flag = 1;
                break;
            }
            y.push_back(X_tmp);
        }
        if (!flag) {
            ui->widget->addGraph();
            ui->widget->graph(0)->addData(x,y);
            ui->widget->replot();
        }
    } else {
        ui->expression->setText("Такое я не нарисую :(");
    }
}

void GraphWindow::setData(const QString &exp) {
    ui->expression->setText(exp);
}

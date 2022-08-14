#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->one, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->two, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->three, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->four, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->five, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->six, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->seven, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->eight, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->nine, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->opening_bracket, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->closing_bracket, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->pow, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->plus, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->minus, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->mul, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->div, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->dot, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->sin, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->cos, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->tan, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->asin, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->acos, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->atan, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->ln, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->log, SIGNAL(clicked()), this, SLOT(init()));
    connect(ui->x_button, SIGNAL(clicked()), this, SLOT(init()));
    ui->res_window->setValidator(val_form);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init() {
    QString exp;
    QPushButton *button = (QPushButton *)sender();
    exp = (ui->res_window->text() + button->text());
    ui->res_window->setText(exp);
}

void MainWindow::on_mod_clicked()
{
    ui->res_window->setText(ui->res_window->text() + "%");
    ui->res_window->setValidator(val_form);
}


void MainWindow::on_equals_clicked()
{
    std::string exp_string = ui->res_window->text().toUtf8().data();
    if (std::count(exp_string.begin(), exp_string.end(), '(') == std::count(exp_string.begin(), exp_string.end(), ')')) {
        ui->res_window->setValidator(val_form);
        const char *exp_tmp = exp_string.c_str();
        char *exp = new char[strlen(exp_tmp) + 1];
        strlcpy(exp, exp_tmp, strlen(exp_tmp)+1);
        double x_value_num = ui->x_value->text().toDouble();
        double res = from_infix_to_postfix(exp, x_value_num);
        if (res == INFINITY || res != res) {
            ui->res_window->setText("Упс, где-то ошибка");
        } else {

            ui->res_window->setText(QString::number(res));
        }
    } else {
         ui->res_window->setText("Упс, где-то ошибка");
    }
}

void MainWindow::on_del_clicked()
{
    std::string rdctstr = ui->res_window->text().toUtf8().constData();
    std::string result = rdctstr.substr(0, rdctstr.length() - 1);
    ui->res_window->setText(QString::fromStdString(result));
}


void MainWindow::on_AC_clicked()
{
    ui->res_window->setText("");
}


void MainWindow::on_graph_clicked()
{
    QString exp = ui->res_window->text();
    GraphWindow graph;
    graph.setData(exp);
    graph.setModal(true);
    graph.exec();
}


void MainWindow::on_credit_clicked()
{
    CreditWindow credit;
    credit.setModal(true);
    credit.exec();
}

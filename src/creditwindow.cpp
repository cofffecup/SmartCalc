#include "creditwindow.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditWindow), d_val(1, 100000000000, 2, this),
    i_val(1, 10000000, this)
{
    ui->setupUi(this);
    d_val.setNotation(QDoubleValidator::StandardNotation);
    ui->summ->setValidator(&d_val);
    ui->rate->setValidator(&d_val);
    ui->years->setValidator(&i_val);

}

CreditWindow::~CreditWindow()
{
    delete ui;
}

void CreditWindow::on_action_clicked()
{
    double i = ui->rate->text().toDouble();
    int n = ui->years->text().toInt();
    double S = ui->summ->text().toDouble();
    i = i*0.01/12;
    if (ui->annuity->isChecked()) {
        ui->big_payment->setText("");
        double P = S*(i/(1-pow((1+i), -1*n)));
        QString P_string = QString::number(P);
        ui->payment->setText(P_string);
        double SUM = P*n;
        QString SUM_string = QString::number(SUM);
        ui->total_payment->setText(SUM_string);
        double over = SUM - S;
        QString over_string = QString::number(over);
        ui->overpayment->setText(over_string);
    } else if (ui->differentiated->isChecked()) {
        ui->payment->setText("");
        double SUM = 0;
        double p = S/n;
        QString res = "";
        for (int j = 0; j <= n; j++) {
            double P = (S - p*j) * i;
            QString P_string = QString::number(P);
            QString j_string = QString::number(j);
            res += j_string + " - " + P_string + " руб\n";
            SUM += P;
        }
        ui->big_payment->setText(res);
        QString SUM_string = QString::number(SUM);
        ui->overpayment->setText(SUM_string);
        double over = SUM + S;
        QString over_string = QString::number(over);
        ui->total_payment->setText(over_string);
    }
}


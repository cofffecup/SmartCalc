#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_action_clicked();

private:
    Ui::CreditWindow *ui;
    QDoubleValidator d_val;
    QIntValidator i_val;
};

#endif // CREDITWINDOW_H

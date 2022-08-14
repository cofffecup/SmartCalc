#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>

#ifdef __cplusplus
extern "C" {
#endif
    #include "calc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

    double xBegin, xEnd, yBegin, yEnd, h, X;
    int N;

    QVector<double> x, y;

    void setData(const QString &exp);

private slots:
    void on_button_clicked();

private:
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H

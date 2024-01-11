#ifndef RUNWINDOW_H
#define RUNWINDOW_H
#include "time_slice.h"
#include <QMainWindow>

namespace Ui {
class runwindow;
}

class runwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit runwindow(QWidget *parent = nullptr);
    ~runwindow();

private slots:
    void on_exti_clicked();

public slots:
    void get_output_data(Time_slice::PCB out_data, int row);


private:
    Ui::runwindow *ui;
};

#endif // RUNWINDOW_H

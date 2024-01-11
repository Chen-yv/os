#ifndef RUNWINDOW_H
#define RUNWINDOW_H
#include "time_slice.h"
#include <QMainWindow>
#include "sjf.h"
namespace Ui {
class runwindow;
}

class runwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit runwindow(QWidget *parent = nullptr);
    ~runwindow();
    void clear();

private slots:
    void on_exti_clicked();

public slots:
    void get_output_data(Time_slice::PCB out_data);
    void get_output_sjf_data(SJF::Process out_data);


private:
    Ui::runwindow *ui;
};

#endif // RUNWINDOW_H

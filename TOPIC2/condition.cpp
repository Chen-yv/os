#include "condition.h"
#include "ui_condition.h"
#include "QTimer"

condition::condition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::condition)
{
    ui->setupUi(this);
    this->setWindowTitle("运行结果");
    this->resize(1094, 788);
}

condition::~condition()
{
    delete ui;
}

void condition::on_exit_clicked()
{
    this->close();
}
void condition::get_output_data(Time_slice::PCB out_data){
    //    QTimer mtime;
    ui->output->setItem(out_data.row, 0, new QTableWidgetItem(out_data.id));
    ui->output->setItem(out_data.row, 1, new QTableWidgetItem(QString::number(out_data.arrivetime, 10)));
    ui->output->setItem(out_data.row, 2, new QTableWidgetItem(QString::number(out_data.runtime, 10)));
    ui->output->setItem(out_data.row, 3, new QTableWidgetItem(QString::number(out_data.finishtime, 10)));
    ui->output->setItem(out_data.row, 4, new QTableWidgetItem(QString::number(out_data.waitTime, 10)));
    ui->output->setItem(out_data.row, 5, new QTableWidgetItem(QString::number(out_data.zhouzhuantime, 10)));

    //    ui->output->viewport()->update();
}
void condition::get_output_sjf_data(SJF::Process out_data){
    ui->output->setItem(out_data.row, 0, new QTableWidgetItem(out_data.name));
    ui->output->setItem(out_data.row, 1, new QTableWidgetItem(QString::number(out_data.arrivalTime, 10)));
    ui->output->setItem(out_data.row, 2, new QTableWidgetItem(QString::number(out_data.burstTime, 10)));
    ui->output->setItem(out_data.row, 3, new QTableWidgetItem(QString::number(out_data.completionTime, 10)));
    ui->output->setItem(out_data.row, 4, new QTableWidgetItem(QString::number(out_data.waitingTime, 10)));
    ui->output->setItem(out_data.row, 5, new QTableWidgetItem(QString::number(out_data.turnaroundTime, 10)));
}

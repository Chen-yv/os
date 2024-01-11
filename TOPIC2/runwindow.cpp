#include "runwindow.h"
#include "ui_runwindow.h"

runwindow::runwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::runwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("运行过程");

}

runwindow::~runwindow()
{
    delete ui;
//    ui->run->clear();
}
void runwindow::clear(){
    ui->run->clear();

}
void runwindow::on_exti_clicked()
{
    this->close();
}
void runwindow::get_output_data(Time_slice::PCB out_data){
    if(out_data.sy){
        ui->run->setText(ui->run->toPlainText()+"进程号："+out_data.id+
                         "\n到达时间："+(QString::number(out_data.arrivetime, 10))+
                         "\n服务时间："+(QString::number(out_data.runtime, 10))+
                         "\n完成时间："+(QString::number(out_data.finishtime, 10))+"\n\n");
        out_data.sy = true;
    }
}
void runwindow::get_output_sjf_data(SJF::Process out_data){
    ui->run->setText(ui->run->toPlainText()+"进程号:"+out_data.name+
                     "\n到达时间："+(QString::number(out_data.arrivalTime, 10))+
                     "\n服务时间："+QString::number(out_data.burstTime, 10)+
                     "\n完成时间："+QString::number(out_data.completionTime, 10)+
                     "\n等待时间："+QString::number(out_data.waitingTime, 10)+
                     "\n周转时间："+QString::number(out_data.turnaroundTime, 10)+"\n\n");
}

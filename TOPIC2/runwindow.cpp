#include "runwindow.h"
#include "ui_runwindow.h"

runwindow::runwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::runwindow)
{
    ui->setupUi(this);

}

runwindow::~runwindow()
{
    delete ui;
}

void runwindow::on_exti_clicked()
{
    this->close();
}
void runwindow::get_output_data(Time_slice::PCB out_data, int row){
    int t = row;
    row = t;
    ui->run->setText(ui->run->toPlainText()+
                     "进程号:"+out_data.id+
                     "\n开始运行时间:"+(QString::number(out_data.runtime, 10))+
                     "\n结束运行时间:"+QString::number(out_data.finishtime, 10)+"\n\n");
//    ui->run->setText("sakjdfhkjsadhgfkjasdf");
}

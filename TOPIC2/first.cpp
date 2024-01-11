#include "first.h"
#include "ui_first.h"
#include "QString"
#include "QtDebug"
#include <QTimer>


first::first(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::first)
{
    ui->setupUi(this);
    this->setWindowTitle("11组操作系统作业");//设置窗口标题

    this->resize(702,1008);//重设窗口大小

    //创建状态栏
    QStatusBar *status = new QStatusBar(this);
    status->setObjectName("状态栏");
    status->setStyleSheet("QStatusBar::item{border: 0px}"); //设置不显示label的边框

    //主窗口添加状态栏
    this->setStatusBar(status);

    //创建标签
    QLabel *statusLabel = new QLabel("版本号：1.0.0", this);

    //状态栏添加信息
    status->showMessage("程序加载中...", 3000);//显示在左侧，并且3秒后自动消失

    status->addPermanentWidget(statusLabel);//添加右侧标签(永久性)

}




void first::on_submit_clicked()
{

    if(ui->dispath->currentText() == "时间片轮转调度法"){
        runui.show();
        runui.clear();
        Time_slice rundata;
        //    rundata的定义在first最前面
        rundata.n = ui->number_of_progoam->value();
        rundata.stime = ui->time_slice->value();
        for (int row = 0; row < rundata.n; row ++) {
            rundata.process[row].id = ui->input->item(row, 0)->text();
            rundata.process[row].arrivetime = ui->input->item(row, 1)->text().toInt();
            rundata.process[row].runtime = ui->input->item(row, 2)->text().toInt();
            rundata.process[row].resttime = rundata.process[row].runtime;
            rundata.totaltime += rundata.process[row].runtime;
            rundata.process[row].row = row;
        }

        connect(&rundata, &Time_slice::send_output_data, &runui, &runwindow::get_output_data);
        connect(&rundata, &Time_slice::send_output_data, &outui, &condition::get_output_data);
        rundata.RR_MAIN();
    }
    else if(ui->dispath->currentText() == "短进程优先调度法"){
        SJF sjf_rundata;
        runui.show();
        sjf_rundata.n = ui->number_of_progoam->value();

        vector<SJF::Process>processes(ui->number_of_progoam->value());

        for (int row = 0; row < ui->number_of_progoam->value(); row++) {
            processes[row].name = ui->input->item(row, 0)->text();
            processes[row].arrivalTime = ui->input->item(row, 1)->text().toInt();
            processes[row].burstTime = ui->input->item(row, 2)->text().toInt();
            processes[row].row = row;
        }

        connect(&sjf_rundata, &SJF::send_sjf_data, &runui, &runwindow::get_output_sjf_data);
        connect(&sjf_rundata, &SJF::send_sjf_data, &outui, &condition::get_output_sjf_data);
        sjf_rundata.SJF_MAIN(processes);
    }

}

void first::on_exit_clicked()
{
    this->~first();
}

void first::on_condition_clicked()
{
    outui.show();
}
first::~first()
{
    delete ui;
}

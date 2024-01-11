#include "time_slice.h"
#include "qdebug.h"
#include "QTimer"
Time_slice::Time_slice(QObject *parent) : QObject(parent)
{

}
void Time_slice::RR_MAIN(void){
    int time = 0;//时刻设为0
    sort(process, process+n, sortByArrivalTime);//按到达时间排序
    queue<PCB> q;//名字为q的队列
    for (int i = 0; i < n; i++)
    {
        q.push(process[i]);//循环入队
    }
    int times = stime; //时间片赋值
    time = q.front().arrivetime;
    while (true)
    {
        if (times == 0) // 重置时间片
        {
            times = stime;
        }
        if (q.front().arrivetime > time)
        {
            q.push(q.front());
            q.pop();
            continue;
        }
        q.front().begintime = time;
        while (times != 0)
        {
            --times;
            ++time;
            --q.front().resttime;
            if (q.front().resttime == 0)
                break;
        }
        q.front().finishtime = time;

        emit send_output_data(q.front());//发送信号

        if (q.front().resttime != 0)
        {
            q.push(q.front());
            q.pop();
        }
        else
        {
            q.front().zhouzhuantime = time - q.front().arrivetime;
            q.front().weightzhouzhuantime = q.front().zhouzhuantime / (double)q.front().runtime;
            weighttotaltime += q.front().weightzhouzhuantime;

            q.front().waitTime = q.front().zhouzhuantime - q.front().runtime;


            q.front().sy = false;
            emit send_output_data(q.front());//发送信号
            q.pop();
            times = 0;
        }
        if (q.empty())
            break;
    }

}

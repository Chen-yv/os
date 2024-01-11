#ifndef SJF_H
#define SJF_H

#include <QObject>
#include <vector>
#include <algorithm>
#include "QString"

using namespace std;


class SJF : public QObject
{
    Q_OBJECT
public:
    explicit SJF(QObject *parent = nullptr);

    struct Process {
        QString name;
        int arrivalTime;
        int burstTime;
        int completionTime;
        int waitingTime;
        int turnaroundTime;
        int row;
    };

    int n;

    static bool sortByArrivalTime(const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    }

//    struct Process {
//        QString name;
//        int arrivalTime;
//        int burstTime;
//        int completionTime;
//        int waitingTime;
//        int turnaroundTime;
//        int row;//是第几行的数
//    }sendprocesses;

//    int n;//进程数


//    static bool compareArrivalTime(const Process& p1, const Process& p2) {
//        return p1.arrivalTime < p2.arrivalTime;
//    }

    void SJF_MAIN(vector<Process> &processes);
signals:
    void send_sjf_data(Process output_data);
};

#endif // SJF_H

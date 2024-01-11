#include "sjf.h"
#include "QDebug"

SJF::SJF(QObject *parent) : QObject(parent)
{

}
void SJF::SJF_MAIN(vector<Process> &processes){

//    int numProcesses;
//       cout << "请输入进程数：";
//       cin >> numProcesses;

       processes.resize(n);

       // 输入进程信息
//       for (int i = 0; i < n; i++) {
//           cout << "请输入进程名、到达时间和运行时间" << i + 1 << ": ";
//           cin >> processes[i].name >> processes[i].arrivalTime >> processes[i].burstTime;
//       }

       // 根据到达时间排序
       sort(processes.begin(), processes.end(), sortByArrivalTime);

       int currentTime = 0;
       for (int i = 0; i < n; i++) {
           if (currentTime < processes[i].arrivalTime) {
               currentTime = processes[i].arrivalTime;
           }

           int shortestBurstTime = processes[i].burstTime;
           int shortestBurstIndex = i;
           for (int j = i; j < n; j++) {
               if (processes[j].arrivalTime <= currentTime && processes[j].burstTime < shortestBurstTime) {
                   shortestBurstTime = processes[j].burstTime;
                   shortestBurstIndex = j;
               }
           }

           // 以最短的运行时间安排进程
           swap(processes[i], processes[shortestBurstIndex]);
           processes[i].completionTime = currentTime + processes[i].burstTime;
           processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
           processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
           currentTime = processes[i].completionTime;

           emit send_sjf_data(processes[i]);
       }
}

// WAP C++ program for implementation of  FCFS CPU Scheduling (Processes with different arrival times)

#include <iostream>
#include <stdlib.h>
using namespace std;
// class process with all the time values and functions

class Process
{
    int id, bt, at, ct, tat, wt;

public:
    void input(Process *, int);
    void calc(Process *, int);
    void show(Process *, int);
    void sort(Process *, int);
};
// main function
int main()
{
    // cout << endl;
    int n;
    cout << "\nEnter the no of processes in your system: ";
    cin >> n;
    Process *p = new Process[n];
    Process f;
    f.input(p, n);
    f.sort(p, n);
    f.calc(p, n);
    f.show(p, n);
    cout << "\n\n";
    return 0;
}

// taking input arrival and burst times for all processes
void Process::input(Process *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter pival time for process " << i + 1 << ": ";
        cin >> p[i].at;
        cout << "\nEnter burst time for process " << i + 1 << ": ";
        cin >> p[i].bt;
        p[i].id = i + 1;
    }
}

// calculating waiting, turn-around and completion time
void Process::calc(Process *p, int n)
{
    int sum = 0;
    sum = sum + p[0].at;
    for (int i = 0; i < n; i++)
    {
        sum = sum + p[i].bt;
        p[i].ct = sum;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        if (sum < p[i + 1].at)
        {
            int t = p[i + 1].at - sum;
            sum = sum + t;
        }
    }
}

// Sorting processes with respect to arrival times (needed for synchronized input)
void Process::sort(Process *p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                int temp;
                // sorting burst times
                temp = p[j].bt;
                p[j].bt = p[j + 1].bt;
                p[j + 1].bt = temp;
                // sorting arrival times
                temp = p[j].at;
                p[j].at = p[j + 1].at;
                p[j + 1].at = temp;
                // sorting their respective IDs
                temp = p[j].id;
                p[j].id = p[j + 1].id;
                p[j + 1].id = temp;
            }
        }
    }
}

// display function
void Process::show(Process *p, int n)
{
    cout << "Process\tArrival\tBurst\tWaiting\tTurn Around\tCompletion\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  P[" << p[i].id << "]\t  " << p[i].at << "\t" << p[i].bt << "\t" << p[i].wt << "\t   " << p[i].tat << "\t\t" << p[i].ct << "\n";
    }
}
// oreo
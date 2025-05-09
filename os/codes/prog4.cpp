// Practical 4
// Write a program to implement Priority CPU Scheduling Algorithm.

#include <iostream>
using namespace std;
int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20];
    int i, j, n, total = 0, pos, temp, avg_wt, avg_tat;
    cout << "Enter Total Number of Process: ";
    cin >> n;
    cout << "Enter Burst Time and Priority for process:\n";
    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "] \t";
        cin >> bt[i]; // BURST TIME
        cin >> pr[i]; // PRIORITY
        p[i] = i + 1; // assisgning process id
    }
    // sorting burst time, priority and procesd id in ascending order using
    // selection sort
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0; // waiting time of first process is zero
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j]; // calculation of waiting time
        total += wt[i];
    }
    avg_wt = total / n; // Average waiting time
    // average waiting time
    total = 0;
    cout << "Process \tBurst Time \tWaiting Time \tTurnaround Time \n";
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // calculation of turnaround time
        total += tat[i];
        cout << " P[" << p[i] << "]" << " \t \t" << bt[i] << "\t \t" << wt[i] << "\t\t " << tat[i] << "\n";
    }
    avg_tat = total / n; // Average turnaround time
    cout << "\nAverage Waiting Time= " << avg_wt;
    cout << "\nAverage Turnaround Time= " << avg_tat << "\n\n";
    return 0;
}

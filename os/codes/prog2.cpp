#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
};

bool compareArrivalTime(const Process &a, const Process &b)
{
    return a.arrival_time < b.arrival_time;
}

bool compareBurstTime(const Process &a, const Process &b)
{
    return a.burst_time < b.burst_time;
}

void sjfNonPreemptive(vector<Process> &processes)
{
    sort(processes.begin(), processes.end(), compareArrivalTime);
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    vector<int> completion_time(n);
    vector<int> waiting_time(n);
    vector<int> turnaround_time(n);
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (processes[j].arrival_time <= current_time && completion_time[j] == 0)
            {
                if (idx == -1 || processes[j].burst_time < processes[idx].burst_time)
                {
                    idx = j;
                }
            }
        }
        if (idx == -1)
        {
            current_time++;
            i--;
            continue;
        }
        current_time += processes[idx].burst_time;
        completion_time[idx] = current_time;
        turnaround_time[idx] = completion_time[idx] - processes[idx].arrival_time;
        waiting_time[idx] = turnaround_time[idx] - processes[idx].burst_time;
        total_waiting_time += waiting_time[idx];
        total_turnaround_time += turnaround_time[idx];
    }
    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    cout << "SJF (Non-preemptive) Scheduling:" << endl;
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].pid << "\t\t"
             << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time << "\t\t"
             << completion_time[i] << "\t\t"
             << waiting_time[i] << "\t\t"
             << turnaround_time[i] << endl;
    }
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

void sjfPreemptive(vector<Process> &processes)
{
    sort(processes.begin(), processes.end(), compareArrivalTime);
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    int completed = 0;
    vector<int> remaining_time(n);
    vector<int> waiting_time(n);
    vector<int> turnaround_time(n);
    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = processes[i].burst_time;
    }
    while (completed != n)
    {
        int shortest = -1; // Initialize to -1 to indicate no process selected
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0)
            {
                if (shortest == -1 || remaining_time[i] < remaining_time[shortest])
                {
                    shortest = i;
                }
            }
        }
        if (shortest == -1) // No process is ready to execute
        {
            current_time++;
            continue;
        }
        remaining_time[shortest]--;
        if (remaining_time[shortest] == 0)
        {
            completed++;
            turnaround_time[shortest] = current_time + 1 - processes[shortest].arrival_time;
            waiting_time[shortest] = turnaround_time[shortest] - processes[shortest].burst_time;
            total_waiting_time += waiting_time[shortest];
            total_turnaround_time += turnaround_time[shortest];
        }
        current_time++;
    }
    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    cout << "SJF (Preemptive) Scheduling:" << endl;
    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].pid << "\t\t"
             << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time << "\t\t"
             << waiting_time[i] << "\t\t"
             << turnaround_time[i] << endl;
    }
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    cout << "Enter arrival time and burst time for each process: " << endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        cout << "Process " << i + 1 << ": " << endl;
        cout << "Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Burst Time: ";
        cin >> processes[i].burst_time;
    }
    sjfNonPreemptive(processes);
    sjfPreemptive(processes);
    return 0;
}
// oreo
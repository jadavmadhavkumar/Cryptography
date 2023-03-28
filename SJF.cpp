#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool operator<(const Process &p) const {
        return burst_time < p.burst_time;
    }
};

void SJF(vector<Process> processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end(), [](Process &p1, Process &p2) {
        return p1.arrival_time < p2.arrival_time;
    });

    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        Process &p = processes[i];
        current_time += p.burst_time;
        p.completion_time = current_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.burst_time - p.turnaround_time;

        total_waiting_time += p.waiting_time;
        total_turnaround_time += p.turnaround_time;

        cout << "P"<<p.pid << "\t\t" << p.arrival_time << "\t\t" << p.burst_time << "\t\t" << p.completion_time << "\t\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << avg_waiting_time << "\n";
    cout << "\nAverage Turnaround Time: " << avg_turnaround_time << "\n";
}

int main() {

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the details of Process " << i+1 << ":\n";
        cout << "PID: ";
        cin >> processes[i].pid;
        cout << "Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Burst Time: ";
        cin >> processes[i].burst_time;
    }

    cout << "The processes entered are:\n"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Process " << processes[i].pid << ": Arrival Time = " << processes[i].arrival_time << ", Burst Time = " << processes[i].burst_time << "\n";
    }
    cout<<endl;
    SJF(processes);
    return 0;
}

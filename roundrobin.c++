//ROUUNDROBIN
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, time = 0, remain, tq, total_wait = 0, total_turnaround = 0;
    cout << "Enter Total Processes: ";
    cin >> n;
    remain = n;

    vector<int> arrival(n), burst(n), remaining(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival and Burst Time for Process " << i + 1 << ": ";
        cin >> arrival[i] >> burst[i];
        remaining[i] = burst[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    cout << "\nProcess | Turnaround Time | Waiting Time\n";
    for (int i = 0; remain;) {
        if (remaining[i] > 0) {
            int exec_time = min(remaining[i], tq);
            time += exec_time;
            remaining[i] -= exec_time;

            if (remaining[i] == 0) {
                remain--;
                int turnaround = time - arrival[i], wait = turnaround - burst[i];
                total_wait += wait;
                total_turnaround += turnaround;
                cout << "P[" << i + 1 << "]\t|\t" << turnaround << "\t|\t" << wait << "\n";
            }
        }
        i = (i + 1) % n;
        while (arrival[i] > time && remain) i = (i + 1) % n;
    }

    cout << "\nAverage Waiting Time = " << (float)total_wait / n << "\n";
    cout << "Average Turnaround Time = " << (float)total_turnaround / n << "\n";
    return 0;
}

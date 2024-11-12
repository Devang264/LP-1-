#include <iostream>
#include <vector>
using namespace std;

void findAvgTime(const vector<int>& bt) {
    int n = bt.size(), total_wt = 0, total_tat = 0;
    vector<int> wt(n), tat(n);
    
    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "Process " << i + 1 << ":\tBurst " << bt[i] << "\tWaiting " << wt[i] << "\tTurn Around " << tat[i] << "\n";
    }
    cout << "Average Waiting Time = " << (float)total_wt / n << "\n";
    cout << "Average Turn Around Time = " << (float)total_tat / n << "\n";
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> bt(n);
    cout << "Enter the burst times for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " burst time: ";
        cin >> bt[i];
    }

    findAvgTime(bt);
    return 0;
}

//PRIORITY
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter Number of Processes: ";
    cin >> n;

    vector<int> burst(n), priority(n), index(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time and Priority for Process " << i + 1 << ": ";
        cin >> burst[i] >> priority[i];
        index[i] = i + 1;
    }
    // Sorting by priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[j] > priority[i]) {
                swap(priority[i], priority[j]);
                swap(burst[i], burst[j]);
                swap(index[i], index[j]);
            }
        }
    }
    int time = 0;
    cout << "Execution Order:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << index[i] << " from " << time << " to " << time + burst[i] << endl;
        time += burst[i];
    }
    int waitTime = 0;
    cout << "\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << index[i] << "\t|\t" << burst[i] << "\t|\t" << waitTime << "\t|\t" << waitTime + burst[i] << endl;
        waitTime += burst[i];
    }
    return 0;
}

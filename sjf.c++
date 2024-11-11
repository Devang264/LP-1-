//SJF
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, wat = 0, att = 0;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), p(n), wt(n), ft(n), st(n), tt(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter process ID and burst time for process " << i + 1 << ": ";
        cin >> p[i] >> bt[i];
    }

    // Sorting processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                swap(bt[j], bt[j + 1]);
                swap(p[j], p[j + 1]);
            }
        }
    }

    st[0] = 0; ft[0] = bt[0];
    for (int i = 1; i < n; i++) {
        st[i] = st[i - 1] + bt[i - 1];
        ft[i] = st[i] + bt[i];
    }

    cout << "\nBurst Time | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        wt[i] = st[i]; tt[i] = ft[i];
        cout << bt[i] << "\t\t" << wt[i] << "\t\t" << tt[i] << endl;
        wat += wt[i]; att += tt[i];
    }

    cout << "\nAverage Waiting Time: " << wat / n << endl;
    cout << "Average Turnaround Time: " << att / n << endl;

    return 0;
}
4
//fifo
#include <iostream>
#include <vector>
#include <algorithm> // For std::find
using namespace std;

void FIFO() {
    vector<int> incomingStream = {1, 3, 0, 3, 5, 6, 3};
    int frames = 3, pageFaults = 0;
    vector<int> temp(frames, -1);

    cout << "Incoming\tFrame 1\t\tFrame 2\t\tFrame 3\n";
    for (int page : incomingStream) {
        if (find(temp.begin(), temp.end(), page) == temp.end()) {  // Page not found
            temp[pageFaults++ % frames] = page;  // Replace page
        }
        cout << page << "\t\t";
        for (int frame : temp) cout << (frame == -1 ? "-\t\t" : to_string(frame) + "\t\t");
        cout << "\n";
    }
    cout << "Total Page Faults:\t" << pageFaults << endl;
}

int main() {
    FIFO();
    return 0;
}

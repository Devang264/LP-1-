//LRU
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LRU() {
    vector<int> pages = {7, 6, 1, 9, 9, 8, 2, 3, 0, 4};
    vector<int> frames(4, -1);
    int page_faults = 0;

    cout << "Page\tFrames\n";
    for (int page : pages) {
        auto it = find(frames.begin(), frames.end(), page);

        // If page is not in frames
        if (it == frames.end()) {
            // If there's an empty frame, insert there; otherwise, replace using LRU
            if (find(frames.begin(), frames.end(), -1) != frames.end())
                *find(frames.begin(), frames.end(), -1) = page;
            else {
                vector<int> temp(frames.size(), 0);

                for (int k = pages.size() - 1, count = 0; count < frames.size(); count++, k--)
                    if (auto it = find(frames.begin(), frames.end(), pages[k]); it != frames.end())
                        temp[it - frames.begin()] = 1;

                frames[find(temp.begin(), temp.end(), 0) - temp.begin()] = page;
            }
            page_faults++;
        }

        // Display current frames
        cout << page << "\t";
        for (int frame : frames) cout << (frame == -1 ? "-\t" : to_string(frame) + "\t");
        cout << "\n";
    }

    cout << "Total Page Faults:\t" << page_faults << endl;
}

int main() {
    LRU();
    return 0;
}

//LRU

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lruPageReplacement(vector<int> pages, int frames) {
    vector<int> memory;
    int pageFaults = 0;

    for (int page : pages) {
        cout << "Requesting page: " << page << endl;
        auto it = find(memory.begin(), memory.end(), page);

        if (it == memory.end()) {  // Page fault
            if (memory.size() < frames) {
                memory.push_back(page);
            } else {
                memory.erase(memory.begin());  // Remove the least recently used page
                memory.push_back(page);
            }
            pageFaults++;
        } else {
            memory.erase(it);  // Remove the page from its current position
            memory.push_back(page);  // Move it to the most recent position
        }

        cout << "Memory: ";
        for (int m : memory) cout << m << " ";
        cout << endl;
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}

int main() {
    vector<int> pages = {7, 6, 1, 9, 9, 8, 2, 3, 0, 4};
    int frames = 4;
    lruPageReplacement(pages, frames);
    return 0;
}

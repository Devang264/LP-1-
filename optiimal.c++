//optimal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Optimal() {
    vector<int> inputStream = {0, 7, 2, 4, 0, 4, 3, 2, 1, 0, 0};
    int frames = 4, faults = 0;
    vector<int> memory(frames, -1);

    for (int page : inputStream) {
        if (find(memory.begin(), memory.end(), page) == memory.end()) {
            if (auto empty = find(memory.begin(), memory.end(), -1); empty != memory.end()) {
                *empty = page;
            } else {
                vector<int> future(frames, inputStream.size());
                for (int j = 0; j < frames; ++j) 
                    for (int k = inputStream.size() - 1; k >= 0; --k) 
                        if (memory[j] == inputStream[k]) { future[j] = k; break; }
                memory[distance(future.begin(), max_element(future.begin(), future.end()))] = page;
            }
            faults++;
        }
        
        for (int frame : memory) cout << (frame == -1 ? "- " : to_string(frame) + " ");
        cout << "\n";
    }
    cout << "Total Page Faults: " << faults << endl;
}

int main() {
    Optimal();
    return 0;
}

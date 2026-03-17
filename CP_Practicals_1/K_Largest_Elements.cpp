#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Hardcoded input values
    int N = 6;
    int K = 3;
    vector<int> nums = {7, 10, 4, 3, 20, 15};

    // Max-heap (priority_queue uses a max-heap by default)
    priority_queue<int> maxHeap;
    for (int x : nums) {
        maxHeap.push(x);
    }

    // Extract the K largest elements
    for (int i = 0; i < K && !maxHeap.empty(); ++i) {
        cout << maxHeap.top();
        maxHeap.pop();
        if (i < K - 1 && !maxHeap.empty()) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

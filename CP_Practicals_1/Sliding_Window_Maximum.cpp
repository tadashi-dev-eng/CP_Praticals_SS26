# include <iostream>
# include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; 

    for (int i = 0; i < nums.size(); ++i) {
        
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    int N = 8;
    int k = 3;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    cout << "Input array: ";
    for (int v : arr) {
        cout << v << " ";
    }
    cout << endl;

    vector<int> output = maxSlidingWindow(arr, k);

    cout << "Sliding window maximums (k=" << k << "): ";
    for (int v : output) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    deque<int> dq;
    vector<long long> result;

    for (int i = 0; i < N; i++) {
        // remove out-of-window indices
        if (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }

        // maintain elements in dq in decreasing order
        while (!dq.empty() && A[i] >= A[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= K - 1) {
            result.push_back(A[dq.front()]);
        }
    }

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i + 1 < (int)result.size()) cout << ' ';
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long target;
    cin >> N >> target;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // dp[s] = number of subsets with sum exactly s
    vector<long long> dp(target + 1, 0);
    dp[0] = 1; // one subset (empty) sums to 0

    for (int x : arr) {
        // iterate backwards so we don't reuse the current element multiple times
        for (long long s = target; s >= x; --s) {
            dp[s] += dp[s - x];
        }
    }

    cout << dp[target] << endl;
    return 0;
}

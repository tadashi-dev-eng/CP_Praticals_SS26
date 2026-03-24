#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        int ans = 0;
        for (int bit = 31; bit >= 0; bit--) {
            int candidate = ans | (1 << bit);
            int streak = 0;
            bool can = false;

            for (int i = 0; i < N; i++) {
                if ((A[i] & candidate) == candidate) {
                    streak++;
                } else {
                    streak = 0;
                }
                if (streak >= K) {
                    can = true;
                    break;
                }
            }

            if (can) {
                ans = candidate;
            }
        }

        cout << ans;
        if (T) cout << '\n';
    }

    return 0;
}

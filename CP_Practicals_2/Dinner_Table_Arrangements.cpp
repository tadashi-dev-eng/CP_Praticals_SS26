#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        cin >> N;
        vector<uint32_t> allergyMask(N, 0);

        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            uint32_t mask = 0;
            for (int j = 0; j < M; j++) {
                int a;
                cin >> a;
                if (a >= 1 && a <= 30) {
                    mask |= (1u << (a - 1));
                }
            }
            allergyMask[i] = mask;
        }

        if (N <= 1) {
            cout << "YES";
            if (T) cout << '\n';
            continue;
        }

        vector<vector<bool>> canSit(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                canSit[i][j] = ((allergyMask[i] & allergyMask[j]) == 0);
            }
        }

        int fullMask = (1 << N);
        vector<vector<char>> dp(fullMask, vector<char>(N, 0));

        dp[1][0] = 1; 

        for (int mask = 1; mask < fullMask; mask++) {
            if (!(mask & 1)) continue; 

            for (int last = 0; last < N; last++) {
                if (!dp[mask][last]) continue;

                for (int nxt = 0; nxt < N; nxt++) {
                    if (mask & (1 << nxt)) continue;
                    if (!canSit[last][nxt]) continue;
                    dp[mask | (1 << nxt)][nxt] = 1;
                }
            }
        }

        bool possible = false;
        int all = fullMask - 1;
        for (int last = 1; last < N; last++) {
            if (dp[all][last] && canSit[last][0]) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO");
        if (T) cout << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long w;
            if (!(cin >> w)) return 0;
            if (w == -1) continue;
            dist[i][j] = w;
        }
    }

    for (int i = 0; i < n; i++) dist[i][i] = min(dist[i][i], 0LL);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << "All pairs shortest path distances:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF/2) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

 

    return 0;
}

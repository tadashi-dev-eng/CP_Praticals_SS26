#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<pair<int,ll>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (u < 1 || u > N || v < 1 || v > N) continue;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(N + 1, INF);
    dist[1] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        if (u == N) break;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[N] == INF) {
        cout << -1;
    } else {
        cout << dist[N];
    }
    return 0;
}
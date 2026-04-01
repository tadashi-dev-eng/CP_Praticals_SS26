#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;
const ll INF = 1e15;

struct Edge { int u, v; ll w; };

vector<ll> bellman_ford(int n, int src, const vector<Edge>& edges) {
    vector<ll> d(n, INF);
    d[src] = 0;
    for (int i = 0; i < n-1; i++) {
        bool changed = false;
        for (auto &e : edges) {
            if (d[e.u] < INF && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    return d;
}

vector<ll> dijkstra(int n, int src, const vector<vector<pair<int,ll>>>& adj) {
    vector<ll> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &pr : adj[u]) {
            int v = pr.first; ll w = pr.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    vector<vector<pair<int,ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    // add auxiliary node n connected to every node with zero weight
    vector<Edge> bf_edges = edges;
    for (int i = 0; i < n; i++) bf_edges.push_back({n, i, 0});

    vector<ll> h = bellman_ford(n+1, n, bf_edges);
    for (int i = 0; i < n; i++) {
        if (h[i] >= INF) {
            cout << "Graph is disconnected or has unreachable nodes from aux node; aborting\n";
            return 0;
        }
    }

    for (auto &e : edges) {
        
        e.w = e.w + h[e.u] - h[e.v];
        
        if (e.w < 0) {
            cout << "Negative weight cycle detected.\n";
            return 0;
        }
    }

    for (auto &e : edges) {
        adj[e.u].push_back({e.v, e.w});
    }

    vector<vector<ll>> allDist(n, vector<ll>(n, INF));
    for (int u = 0; u < n; u++) {
        vector<ll> dist = dijkstra(n, u, adj);
        for (int v = 0; v < n; v++) {
            if (dist[v] < INF) {
                allDist[u][v] = dist[v] - h[u] + h[v];
            }
        }
    }

    cout << "All-pairs shortest paths with Johnson's algorithm:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (allDist[i][j] >= INF/2) cout << "INF ";
            else cout << allDist[i][j] << " ";
        }
        cout << '\n';
    }

    
    return 0;
}

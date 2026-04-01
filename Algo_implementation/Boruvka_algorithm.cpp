#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int u, v; long long w; };

int find_set(vector<int>& parent, int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a,b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<Edge> mst;
    int components = n;

    while (components > 1) {
        vector<int> cheapest(n, -1);

        for (int i = 0; i < m; i++) {
            int u = find_set(parent, edges[i].u);
            int v = find_set(parent, edges[i].v);
            if (u == v) continue;
            if (cheapest[u] == -1 || edges[i].w < edges[cheapest[u]].w) cheapest[u] = i;
            if (cheapest[v] == -1 || edges[i].w < edges[cheapest[v]].w) cheapest[v] = i;
        }

        bool added = false;
        for (int i = 0; i < n; i++) {
            if (cheapest[i] != -1) {
                int u = find_set(parent, edges[cheapest[i]].u);
                int v = find_set(parent, edges[cheapest[i]].v);
                if (u == v) continue;
                mst.push_back(edges[cheapest[i]]);
                union_sets(parent, rank, u, v);
                components--;
                added = true;
            }
        }

        if (!added) break;
    }

    long long totalWeight = 0;
    cout << "Minimum spanning tree edges (u v w):\n";
    for (auto &e : mst) {
        cout << e.u << " " << e.v << " " << e.w << '\n';
        totalWeight += e.w;
    }
    cout << "Total MST weight = " << totalWeight << '\n';

    
    return 0;
}

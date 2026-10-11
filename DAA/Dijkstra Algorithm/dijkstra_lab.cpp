#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V,
                     vector<vector<int>>& edges,
                     int src) {

    vector<vector<pair<int, int>>> adj(V);

    // Build adjacency list
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // For undirected graph
    }

    vector<int> dist(V, INT_MAX);

    // {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignore outdated entries
        if (d > dist[u])
            continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, 2},
        {1, 3, 1},
        {2, 3, 5},
        {3, 4, 3}
    };

    int src = 0;

    vector<int> ans = dijkstra(V, edges, src);

    for (int i = 0; i < V; i++) {
        cout << "Distance from " << src
             << " to " << i << " = "
             << ans[i] << endl;
    }

    return 0;
}
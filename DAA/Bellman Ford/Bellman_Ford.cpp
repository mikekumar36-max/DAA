#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        bool changed = false;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX &&
                dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                changed = true;
            }
        }

        if (!changed) break;
    }
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INT_MAX &&
            dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected\n";
            return 0;
        }
    }

    cout << "Shortest distances:\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}
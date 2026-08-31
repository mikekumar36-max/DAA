# include <iostream>
# include <vector>
# include <set>
using namespace std;


// Aman Mandal
// 25/DA/011
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

int countComponents(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            count++;
        }
    }

    return count;
}
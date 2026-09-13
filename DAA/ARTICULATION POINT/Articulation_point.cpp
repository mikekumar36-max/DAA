#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    vector<int> disc, low;
    vector<bool> visited, articulation;
    int timer;

    void DFS(int u, int parent) {
        visited[u] = true;

        disc[u] = low[u] = timer++;

        int children = 0;

        for (int v : adj[u]) {

            // Ignore the edge to parent
            if (v == parent)
                continue;

            // If v is already visited
            if (visited[v]) {
                low[u] = min(low[u], disc[v]);
            }

            // If v is not visited
            else {
                children++;

                DFS(v, u);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Case 1: u is root
                if (parent == -1 && children > 1)
                    articulation[u] = true;

                // Case 2: u is not root
                if (parent != -1 && low[v] >= disc[u])
                    articulation[u] = true;
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);

        disc.resize(V, -1);
        low.resize(V, -1);
        visited.resize(V, false);
        articulation.resize(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1);
            }
        }

        cout << "Articulation Points: ";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (articulation[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.findArticulationPoints();

    return 0;
}
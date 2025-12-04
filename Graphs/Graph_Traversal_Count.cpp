#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected graph
    }

    int connectedComponents = 0;

    // Count connected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            connectedComponents++;
            dfs(i, visited, adj);
        }
    }

    cout << connectedComponents << endl;

    return 0;
}

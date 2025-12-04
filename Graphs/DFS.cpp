#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;                        // Number of vertices
    vector<vector<int>> adj;      // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);      // Remove this line if graph is directed
    }

    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        // Visit all unvisited neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int V = 6;                   // Number of vertices
    Graph g(V);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    int startNode = 0;
    cout << "Starting DFS from node " << startNode << endl;
    g.DFS(startNode);

    return 0;
}

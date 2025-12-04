#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;   // (neighbor, weight)

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});     // remove this line for directed graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});    // (distance, node)

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // Skip if outdated entry
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

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " --> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 1);

    int start = 0;

    g.dijkstra(start);

    return 0;
}

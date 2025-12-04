#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    void primMST(int start) {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        int cost = 0;

        cout << "Prim's MST edges:\n";

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;
            cost += key[u];

            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if (!inMST[v] && wt < key[v]) {
                    key[v] = wt;
                    pq.push({key[v], v});
                }
            }
        }

        for (int i = 0; i < V; i++)
            cout << "Vertex " << i << " included with key: " << key[i] << endl;

        cout << "Total MST Cost: " << cost << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    g.primMST(0);
    return 0;
}

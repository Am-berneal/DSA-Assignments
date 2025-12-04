#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, wt;
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);  // Path compression
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int n = 6;   // number of vertices
    vector<Edge> edges;

    // (u, v, weight)
    edges.push_back(Edge(0, 1, 4));
    edges.push_back(Edge(0, 2, 3));
    edges.push_back(Edge(1, 2, 1));
    edges.push_back(Edge(1, 3, 2));
    edges.push_back(Edge(2, 3, 4));
    edges.push_back(Edge(3, 4, 2));
    edges.push_back(Edge(4, 5, 6));

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;
    cout << "Kruskal's MST edges:\n";

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cost += e.wt;
            cout << e.u << " - " << e.v << " (Weight: " << e.wt << ")\n";
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Total MST Cost: " << cost << endl;
    return 0;
}

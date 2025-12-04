#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    vector<vector<pair<int,int>>> adj(N + 1);

    // Build graph: u -> (v, w)
    for (auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }

    // Distance array
    vector<int> dist(N + 1, INT_MAX);

    // Min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int node = top.second;

        if (cost > dist[node]) continue;

        for (auto &edge : adj[node]) {
            int next = edge.first;
            int w = edge.second;

            if (dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push({dist[next], next});
            }
        }
    }

    // Find the maximum time among reachable nodes
    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) return -1; // unreachable
        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<int>> times(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    cout << networkDelayTime(times, N, K) << endl;

    return 0;
}

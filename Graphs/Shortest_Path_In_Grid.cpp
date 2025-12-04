#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dijkstraGrid(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Min-heap -> (cost, (row, col))
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>> > pq;

    // Start at (0,0)
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    // 4 possible directions
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int r = top.second.first;
        int c = top.second.second;

        if (r == m-1 && c == n-1)
            return cost;   // Reached destination

        if (cost > dist[r][c])
            continue;

        // Explore 4 neighbors
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
    }

    return dist[m-1][n-1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << dijkstraGrid(grid) << endl;

    return 0;
}

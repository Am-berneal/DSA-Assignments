#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    int m = grid.size();
    int n = grid[0].size();

    // Out of bounds or water or already visited
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;
    if (grid[r][c] == 0 || visited[r][c])
        return;

    visited[r][c] = true;

    // Move in 4 directions
    dfs(r + 1, c, grid, visited);
    dfs(r - 1, c, grid, visited);
    dfs(r, c + 1, grid, visited);
    dfs(r, c - 1, grid, visited);
}

int numIslands(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int count = 0;

    // Check every cell
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                count++;
                dfs(i, j, grid, visited);
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // Input grid
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << numIslands(grid) << endl;

    return 0;
}

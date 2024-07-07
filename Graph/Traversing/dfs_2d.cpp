#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Directions for moving in the 2D grid (up, down, left, right)
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Mark the current cell as visited
    visited[x][y] = true;
    // cout<<x<<" "<<y<<endl;

    // Explore all four possible directions
    for (const auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        // Check if the new position is within the grid and not visited
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] == 1) {
            dfs(grid, nx, ny, visited);
        }
    }
}

int count_connected_components(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int componentCount = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j] && grid[i][j] == 1) {
                dfs(grid, i, j, visited);
                ++componentCount;
            }
        }
    }

    return componentCount;
}

int32_t main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    cout << "Number of connected components: " << count_connected_components(grid) << endl;

    return 0;
}

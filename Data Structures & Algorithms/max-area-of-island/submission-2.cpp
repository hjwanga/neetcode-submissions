class Solution {
    void dfs(const vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, int& area) {
        static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = grid.size();
        int n = grid[0].size();
        if (grid[r][c] == 0) {
            return;
        }
        if (visited[r][c]) {
            return;
        }
        visited[r][c] = true;

        ++area;
        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
                continue;
            }
            dfs(grid, new_r, new_c, visited, area);
        }
    }
public:
    // water: 0
    // land: 1
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int result = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    dfs(grid, r, c, visited, area);
                    result = max(result, area);
                }
            }
        }
        return result;
    }
};

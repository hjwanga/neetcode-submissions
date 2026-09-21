class Solution {
    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    bool dfs(const vector<vector<int>>& grid, const int level, int r, int c, vector<vector<bool>>& visited) {
        static constexpr int dirs[4][2]{{1,0}, {0,1}, {-1,0}, {0,-1}};
        int m = grid.size();
        int n = grid[0].size();

        if (!is_valid_rc(m, n, r, c)) {
            return false;
        }

        if (grid[r][c] > level) {
            return false;
        }

        if (r == m-1 && c == n-1) {
            return true;
        }

        if (visited[r][c]) {
            return false;
        }
        visited[r][c] = true;

        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (dfs(grid, level, new_r, new_c, visited)) {
                return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 1. guess a water
        int l = 0;
        int r = m*n-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            // 2. DFS
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            if (dfs(grid, mid, 0, 0, visited)) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};

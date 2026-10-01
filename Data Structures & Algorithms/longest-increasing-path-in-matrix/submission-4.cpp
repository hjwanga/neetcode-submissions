class Solution {
    bool is_valid_pos(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    int dfs(const vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& cache) {
        if (cache[r][c] != -1) {
            return cache[r][c];
        }
        static constexpr int dirs[4][2]{{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 1;
        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (!is_valid_pos(m, n, new_r, new_c)) {
                continue;
            }
            if (matrix[r][c] >= matrix[new_r][new_c]) {
                continue;
            }
            int one_sol = dfs(matrix, new_r, new_c, cache);
            result = max(result, one_sol+1);
        }
        return cache[r][c] = result;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<vector<int>> cache(m, vector<int>(n, -1));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int one_sol = dfs(matrix, r, c, cache);
                result = max(result, one_sol);
            }
        }
        return result;
    }
};

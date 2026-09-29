class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp[2]{vector<int>(n, false), vector<int>(n, false)};
        for (int c = 0; c < n; ++c) {
            dp[0][c] = 1;
        }
        for (int r = 1; r < m; ++r) {
            vector<int>& prev = dp[(r+1)%2];
            vector<int>& curr = dp[r%2];
            for (int c = 0; c < n; ++c) {
                if (c == 0) {
                    curr[c] = 1;
                } else {
                    curr[c] = curr[c-1] + prev[c];
                }
            }
        }

        return dp[(m-1)%2][n-1];
    }
};

// dp[i][j] := 走到grid[i][j], 總共有多少unique paths
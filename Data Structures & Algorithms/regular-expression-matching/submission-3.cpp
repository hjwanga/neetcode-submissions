class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // dp[i][j] := s[0...i-1], p[0...j-1] 能match
        // dp[i][j] = dp[i-1][j-1] if s[i-1]==p[j-1] or p[j-1] == '.'
        // dp[i][j] = dp[i][j-2] || dp[i-1][j]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i-1 >= 0 && (s[i-1] == p[j-1] || p[j-1] == '.')) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    // x* : 吃掉0個
                    dp[i][j] = dp[i][j-2];

                    // x* : 吃掉多個
                    if (i-1 >= 0 && (s[i-1] == p[j-2] || p[j-2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

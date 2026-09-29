class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = (i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] + 1 : 1;
                } else {
                    int dp_i_jm1 = j-1 >= 0 ? dp[i][j-1] : 0;
                    int dp_im1_j = i-1 >= 0 ? dp[i-1][j] : 0;
                    dp[i][j] = max(dp_i_jm1, dp_im1_j);
                }
            }
        }

        return dp[m-1][n-1];
    }
};

// dp[i][j] := text1[0..i] 且 text2[0..j]情況下的LCS

// if (i == j) -> dp[i][j] = dp[i-1][j-1] + 1;
// else -> dp[i][j] = max(dp[i][j-1], dp[i-1][j])
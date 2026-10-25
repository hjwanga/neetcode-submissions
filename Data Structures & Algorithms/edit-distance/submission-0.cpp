class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        // base case
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // 新增
                    int op1 = dp[i][j-1]+1;
                    // 刪除 
                    int op2 = dp[i-1][j]+1;
                    // 替換
                    int op3 = dp[i-1][j-1]+1;
                    dp[i][j] = min({op1, op2, op3});
                }
            }
        }

        return dp[m][n];
    }
};



// dp[i][j] := word1[0...i-1] 跟 word2[0...j-1] 的 min operation

// if (word1[i] == word2[j]) -> dp[i][j] = dp[i-1][j-1]
// else:
// 新增: dp[i][j-1] + 1
// 刪除: dp[i-1][j] + 1
// 替換: dp[i-1][j-1] + 1
// dp[i][j] = min(新增, 刪除, 替換)
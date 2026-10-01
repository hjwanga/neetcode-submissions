class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m+n != (int)s3.size()) {
            return false;
        }

        vector<vector<bool>> dp(2, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            vector<bool>& prev = dp[(i+1)%2];
            vector<bool>& curr = dp[i%2];
            for (int j = 0; j <= n; ++j) {
                if (i-1 >= 0 && j-1 >= 0) {
                    curr[j] = (prev[j] && s1[i-1] == s3[i+j-1]) || (curr[j-1] && s2[j-1] == s3[i+j-1]);
                } else if (i-1 >= 0) {
                    curr[j] = (prev[j] && s1[i-1] == s3[i+j-1]);
                } else if (j-1 >= 0) {
                    curr[j] = (curr[j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[m%2][n];
    }
};

// dp[i][j] := s1[0...i-1] (len i) 且 s2[0...j-1] (len j) 能湊出 s3[0..i+j-1] (len i+j)

// dp[i][j] =  s1的尾跟s3尾 || s2尾跟s3尾
// dp[i][j] = (dp[i-1][j] && s1.compare(i-1,1,s3,i+j-1,1) == 0) || (dp[i][j-1] && s2.compare(j-1,1,s3,i+j-1,1) == 0);
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return s[0] == s[1] ? 3 : 2;
        }

        int result = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // len = 1;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        result += n;

        // len = 2
        for (int i = 0; i+1 < n; ++i) {
            int j = i+1;
            dp[i][j] = s[i] == s[j];
            if (dp[i][j]) {
                ++result;
            }
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : false;
                if (dp[i][j]) {
                    ++result;
                }
            }
        }
        return result;
    }
};

// dp[i][j] := s[i..j]是palindrome
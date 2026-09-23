class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }
        if (n == 2) {
            return s[0] == s[1] ? s : string(1, s[0]);
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // len = 1;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // len = 2
        pair<int,int> max_pair;
        for (int i = 0; i+1 < n; ++i) {
            int j = i+1;
            dp[i][j] = s[i] == s[j];
            if (dp[i][j]) {
                max_pair = make_pair(i, j);
            }
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                int j = i+len-1;
                dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : false;
                if (dp[i][j]) {
                    max_pair = make_pair(i, j);
                }
            }
        }
        return s.substr(max_pair.first, max_pair.second-max_pair.first+1);
    }
};

// dp[i][j] := s[i..j]是palindrome
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int len = 1; len <= n; ++len) {
            for (const string& word : wordDict) {
                int m = word.size();
                if (m > len || !dp[len-m] || dp[len]) {
                    continue;
                }
                dp[len] = dp[len] | (s.compare(len-m, m, word) == 0);
            }
        }
        return dp[n];
    }
};

// dp[len] := s[0..len-1] 是否能被wordBreak
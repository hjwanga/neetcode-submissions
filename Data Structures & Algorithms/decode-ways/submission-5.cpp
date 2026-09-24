class Solution {
    bool is_valid_2_cut(const string& s) {
        if (s[0] == '0') {
            return false;
        }
        if (s[0] == '1' || s[0] == '2' && '0' <= s[1] && s[1] <= '6') {
            return true;
        }
        return false;
    }

    bool is_valid_1_cut(const string& s) {
        return s[0] != '0';
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 1) {
            return is_valid_1_cut(s) ? 1 : 0;
        }
        vector<int> dp(n, 0);
        dp[0] = is_valid_1_cut(s.substr(0,1)) ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            int sol1 = 0;
            if (is_valid_1_cut(s.substr(i,1))) {
                sol1 = dp[i-1];
            }
            int sol2 = 0;
            if (is_valid_2_cut(s.substr(i-1,2))) {
                sol2 = i-2 >= 0 ? dp[i-2] : 1;
            }
            dp[i] = sol1 + sol2;
        }
        return dp[n-1];
    }
};

// dp[i] := s[0..i]的numDecodings
// dp[i] = dp[i-1] + dp[i-2]

//1. 切一個 or 切兩個
// -> 切一個: [1,9]
// -> 切兩個: 僅能[10,26]
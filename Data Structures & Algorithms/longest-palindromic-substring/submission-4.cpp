class Solution {
public:
    string longestPalindrome(string s) {
        // 中心擴展法
        int n = s.size();
        int start = -1;
        int max_len = -1;

        auto expand = [&start, &max_len, n](const string& s, int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r-l+1;
                if (len > max_len) {
                    max_len = len;
                    start = l;
                }
                --l;
                ++r;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(s, i, i); // odd center
            expand(s, i, i+1); // even center
        }
        return s.substr(start, max_len);
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        // 中心擴展法
        auto expand = [&result, n](const string& s, int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++result;
                --l;
                ++r;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return result;
    }
};

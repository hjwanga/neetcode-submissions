class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> last;
        int l = 0;
        int result = 0;
        for (int r = 0; r < n; ++r) {
            char c = s[r];
            if (last.count(c)) {
                l = max(l, last[c]+1);
            }
            last[c] = r;
            result = max(result, r-l+1);
        }
        return result;
    }
};

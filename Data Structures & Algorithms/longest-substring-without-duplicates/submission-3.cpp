class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // <char, index>
        unordered_map<char, int> cache;
        int n = s.size();
        int l = 0;
        int result = 0;
        for (int r = 0; r < n; ++r) {
            char c = s[r];
            if (cache.count(c) && l < r) {
                l = max(l, cache[c]+1);
            }
            cache[c] = r;
            result = max(result, r-l+1);
        }
        return result;
    }
};

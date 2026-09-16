class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counts;
        int n = s.size();
        int l = 0;
        int result = 0;
        for (int r = 0; r < n; ++r) {
            char c = s[r];
            // shrink window
            while (counts[c] > 0 && l < r) {
                --counts[s[l]];
                ++l;
            }
            counts[c]++;
            result = max(result, r-l+1);
        }
        return result;
    }
};

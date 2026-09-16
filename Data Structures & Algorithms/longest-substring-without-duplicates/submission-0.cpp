class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int l = 0;
        int result = 0;
        for (int r = 0; r < n; ++r) {
            char c = s[r];
            freq[c]++;
            while (l < r && freq[c] >= 2) {
                freq[s[l]]--;
                ++l;
            }
            result = max(result, r-l+1);
        }
        return result;
    }
};

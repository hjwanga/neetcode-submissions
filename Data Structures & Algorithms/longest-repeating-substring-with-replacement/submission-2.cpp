class Solution {
    int get_longest(char c, const string& s, int k) {
        int result = 0;
        int n = s.size();
        int l = 0;
        // keep replaced character position
        queue<int> poses;
        for (int r = 0; r < n; ++r) {
            if (s[r] != c) {
                --k;
                poses.push(r);
            }
            if (k < 0 && !poses.empty()) {
                int pos = poses.front();
                poses.pop();
                l = pos+1;
                ++k;
            }
            result = max(result, r-l+1);
        }
        return result;
    }
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        // 最外圈可以尋訪 A-Z, 更好的方式是尋訪s有的即可
        unordered_set<char> chars(s.begin(), s.end());
        for (auto it = chars.begin(); it != chars.end(); ++it) {
            char c = *it;
            result = max(result, get_longest(c, s, k));
        }
        return result;
    }
};


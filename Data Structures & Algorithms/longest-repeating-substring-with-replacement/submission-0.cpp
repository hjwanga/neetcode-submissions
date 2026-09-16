class Solution {
    int get_result(char c, const string& s, int k) {
        int result = 0;
        int n = s.size();
        int l = 0;

        for (int r = 0; r < n; ++r) {
            if (c != s[r]) {
                --k;
            }
            while (l <= r && k < 0) {
                if (c != s[l]) {
                    ++k;
                }
                ++l;
            }
            result = max(result, r-l+1);
        }
        return result;
    }
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            result = max(result, get_result('A'+i, s, k));
        }
        return result;
    }
};

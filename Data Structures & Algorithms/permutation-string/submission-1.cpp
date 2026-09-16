class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freqs;
        unordered_map<char, int> curr_freqs;
        for (char c : s1) {
            freqs[c]++;
        }

        int l = 0;
        int m = s1.size();
        int n = s2.size();
        for (int r = 0; r < n; ++r) {
            char c = s2[r];
            if (!freqs.count(c)) {
                l = r+1;
                curr_freqs.clear();
                continue;
            }
            curr_freqs[c]++;
            while (curr_freqs[c] > freqs[c]) {
                if (curr_freqs.count(s2[l])) {
                    curr_freqs[s2[l]]--;
                }
                ++l;
            }
            if (r-l+1 == m) {
                return true;
            }
        }
        return false;
    }
};
// <freqs>
// a:1
// b:0

// s2="eidboaoo"
// l       ^
// r        ^
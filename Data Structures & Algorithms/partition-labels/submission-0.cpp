class Solution {
    void get_interval(const string& s, unordered_map<char, pair<int,int>>& interval) {
        int counts[26]{};
        for (char c : s) {
            counts[c-'a']++;
        }
        int n = s.size();
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 0) {
                continue;
            }
            char c = i+'a';
            interval[c] = make_pair(-1,-1);
            // find 1st c from lhs
            for (int i = 0; i < n; ++i) {
                if (c == s[i]) {
                    interval[c].first = i;
                    break;
                }
            }
            // find 1st c from rhs
            for (int i = n-1; i >= 0; --i) {
                if (c == s[i]) {
                    interval[c].second = i;
                    break;
                }
            }
        }
    }
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>> interval;
        get_interval(s, interval);

        vector<int> result;
        int l = -1;
        int r = -1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            auto lr = interval[c];
            if (l == -1 && r == -1) {
                l = lr.first;
                r = lr.second;
            }
            r = max(r, lr.second);
            if (r == i) {
                result.push_back(r-l+1);
                // reset
                l = -1;
                r = -1;
            }
        }
        return result;
    }
};
//      0123456789ABC
// s = "xyxxyzbzbbisl"
// b:[6,9]
// x:[0,3]
// y:[1,4]
// z:[5,7]
// i:[A,A]
// s:[B,B]
// l:[C,C]
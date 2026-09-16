class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        // collect char counts of t
        int match_count = 0;
        int exp_count = t.size();
        unordered_map<char, int> curr_counts;
        unordered_map<char, int> exp_counts;
        for (char c : t) {
            ++exp_counts[c];
        }

        int min_window = 1001;
        pair<int, int> min_w(-1, -1); // [l,r]
        int l = 0;
        int r = 0;
        int n = s.size();
        // two pointer traverse s to find valid window
        // keep smallest window [l,r]
        for (; r < n; ++r) {
            char c = s[r];
            if (!exp_counts.count(c)) {
                continue;
            }
            curr_counts[c]++;
            if (curr_counts[c] <= exp_counts[c]) {
                ++match_count;
            }

            // valid window
            while (match_count == exp_count && l <= r) {
                // update smallest window
                if (min_window > (r-l+1)) {
                    min_window = r-l+1;
                    min_w = make_pair(l, r);
                }
                if (curr_counts.count(s[l])) {
                    curr_counts[s[l]]--;
                    if (curr_counts[s[l]] < exp_counts[s[l]]) {
                        --match_count;
                    }
                }
                ++l;
            }
        }
        return min_window == 1001 ? "" : s.substr(min_w.first, min_w.second-min_w.first+1);
    }
};

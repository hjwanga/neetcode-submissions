class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs.front();
        int m = first.size();
        int n = strs.size();
        for (int i = 0; i < m; ++i) {
            char c = first[i];
            for (int j = 1; j < n; ++j) {
                if (i >= (int)strs[j].size() || c != strs[j][i]) {
                    return first.substr(0, i);
                }
            }
        }
        return first;
    }
};
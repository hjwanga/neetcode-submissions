class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last_indices[26]{};
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            last_indices[c-'a'] = i;
        }

        vector<int> result;
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int last_index = last_indices[c-'a'];
            r = max(r, last_index);

            if (r == i) {
                result.push_back(r-l+1);
                l = r+1;
                r = i+1;
            }
        }
        return result;
    }
};

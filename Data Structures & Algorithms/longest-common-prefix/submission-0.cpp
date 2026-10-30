class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int m = strs.size();
        int index = 0;
        while (true) {
            int n1 = strs.front().size();
            if (index >= n1) {
                return result;
            }
            char c = strs.front()[index];
            for (int i = 1; i < m; ++i) {
                const string& str = strs[i];
                int n = str.size();
                if (index >= n || c != str[index]) {
                    return result;
                }
            }
            result.push_back(c);
            ++index;
        }
        return "";
    }
};
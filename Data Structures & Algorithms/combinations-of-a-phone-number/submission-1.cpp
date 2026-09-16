class Solution {
    vector<char> maps[8];
    void init_maps() {
        maps[0] = {'a', 'b', 'c'};
        maps[1] = {'d', 'e', 'f'};
        maps[2] = {'g', 'h', 'i'};
        maps[3] = {'j', 'k', 'l'};
        maps[4] = {'m', 'n', 'o'};
        maps[5] = {'p', 'q', 'r', 's'};
        maps[6] = {'t', 'u', 'v'};
        maps[7] = {'w', 'x', 'y', 'z'};
    }
    void dfs(const string& digits, int index, string& one_sol, vector<string>& result) {
        int n = digits.size();
        if (index >= n) {
            result.push_back(one_sol);
            return;
        }
        
        for (char c : maps[digits[index] - '2']) {
            one_sol.push_back(c);
            dfs(digits, index+1, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        init_maps();
        vector<string> result;
        string one_sol;
        dfs(digits, 0, one_sol, result);
        return result;
    }
};

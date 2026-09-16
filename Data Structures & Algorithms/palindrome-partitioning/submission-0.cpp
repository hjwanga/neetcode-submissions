class Solution {
    bool is_palindrome(const string& str) {
        int n = str.size();
        for (int i = 0; i < n/2; ++i) {
            if (str[i] != str[n-i-1]) {
                return false;
            }
        }
        return true;
    }
    // choose len from 1 : end per layer
    void dfs(const string& s, int i, vector<string>& one_sol, vector<vector<string>>& result) {
        int n = s.size();
        if (i >= n) {
            result.push_back(one_sol);
            return;
        }
        
        for (int len = 1; i+len-1 < n; ++len) {
            string str = s.substr(i, len);
            if (!is_palindrome(str)) {
                continue;
            }
            one_sol.push_back(str);
            dfs(s, i+len, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> one_sol;
        dfs(s, 0, one_sol, result);
        return result;
    }
};

// abcba

// a| bcba

// ab | cba

// abc | ba

// abcb| a

// abcba|
class Solution {
    void dfs(int n, int l_count, int r_count, string& one_sol, vector<string>& result) {
        int m = n << 1;
        if ((int)one_sol.size() == m && l_count == r_count) {
            result.push_back(one_sol);
            return;
        }
        // choose L
        if (l_count < n) {
            one_sol.push_back('(');
            dfs(n, l_count+1, r_count, one_sol, result);
            one_sol.pop_back();
        }

        // choose R
        if (l_count > r_count) {
            one_sol.push_back(')');
            dfs(n, l_count, r_count+1, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string one_sol;
        dfs(n, 0, 0, one_sol, result);
        return result;
    }
};


// n = 1
// ()

// n = 2

// ()()
// (())

// n = 3
// ()()()
// (())()
// ()(())
// ((()))
// (()())


// n = 2

// LRLR
// LLRR

// n = 3
// LR LRLR
// LR LLRR

// LLRRLR
// LLRLRR

// LLLRRR

//                   []
//            L             X
//        L           R
//    L     R      L     X
// X    X  L  R
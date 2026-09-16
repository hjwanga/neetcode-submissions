class Solution {
    void dfs(int n, int row, vector<string>& one_sol, vector<bool>& visited_cols, vector<bool>& visited_diag1, vector<bool>& visited_diag2, vector<vector<string>>& result) {
        if (row >= n) {
            result.push_back(one_sol);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (visited_cols[col]) {
                continue;
            }
            if (visited_diag1[row+col]) {
                continue;
            }
            if (visited_diag2[row-col+n-1]) {
                continue;
            }

            visited_cols[col] = true;
            visited_diag1[row+col] = true;
            visited_diag2[row-col+n-1] = true;

            string one_row(n, '.');
            one_row[col] = 'Q';
            one_sol.push_back(one_row);
            dfs(n, row+1, one_sol, visited_cols, visited_diag1, visited_diag2, result);
            one_sol.pop_back();

            visited_diag2[row-col+n-1] = false;
            visited_diag1[row+col] = false;
            visited_cols[col] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<bool> visited_cols(n, false);
        vector<bool> visited_diag1(n*2-1, false);
        vector<bool> visited_diag2(n*2-1, false);
        vector<string> one_sol;
        dfs(n, 0, one_sol, visited_cols, visited_diag1, visited_diag2, result);
        return result;
    }
};
// diag1 /
// diag2 \

// 0,0 0,1
// 1,0 1,1

//  0  1
//  1  2

//  0  -1  -2
//  1   0  -1
//  2   1   0

//  2   1   0
//  3   2   1
//  4   3   2
class Solution {
    int get_submatrix(int row, int col) {
        return (row/3)*3 + col/3;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // One pass
        // Every cell simultaneously check rule1, rule2, and rule3.
        int n = board.size();
        vector<vector<int>> row_counts(n, vector<int>(n+1, 0));
        vector<vector<int>> col_counts(n, vector<int>(n+1, 0));
        vector<vector<int>> submatrix_counts(n, vector<int>(n+1, 0));
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                char c = board[row][col];
                if (c == '.') {
                    continue;
                }
                int num = c - '0';
                // rule1
                if (++row_counts[row][num] >= 2) {
                    return false;
                }

                // rule2
                if (++col_counts[col][num] >= 2) {
                    return false;
                }

                // rule3
                int submatrix = get_submatrix(row, col);
                if (++submatrix_counts[submatrix][num] >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

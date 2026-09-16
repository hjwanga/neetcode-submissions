class Solution {
    int get_submatrix(int row, int col) {
        return (row/3)*3 + col/3;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // One pass
        // Every cell simultaneously check rule1, rule2, and rule3.
        int n = board.size();
        vector<int> row_counts(n, 0);
        vector<int> col_counts(n, 0);
        vector<int> submatrix_counts(n, 0);
        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                char c = board[row][col];
                if (c == '.') {
                    continue;
                }
                int num = c - '0';
                // rule1
                if (row_counts[row] & (1 << num)) {
                    return false;
                }
                row_counts[row] |= 1 << num;

                // rule2
                if (col_counts[col] & (1 << num)) {
                    return false;
                }
                col_counts[col] |= 1 << num;

                // rule3
                int submatrix = get_submatrix(row, col);
                if (submatrix_counts[submatrix] & (1 << num)) {
                    return false;
                }
                submatrix_counts[submatrix] |= 1 << num;
            }
        }
        return true;
    }
};

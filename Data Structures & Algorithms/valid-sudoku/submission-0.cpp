class Solution {
    bool check_rule1(const vector<vector<char>>& board) {
        int n = board.size();
        for (int row = 0; row < n; ++row) {
            int counts[10]{};
            for (int col = 0; col < n; ++col) {
                char c = board[row][col];
                if (c == '.') {
                    continue;
                }
                if (++counts[c-'0'] >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
    bool check_rule2(const vector<vector<char>>& board) {
        int n = board.size();
        for (int col = 0; col < n; ++col) {
            int counts[10]{};
            for (int row = 0; row < n; ++row) {
                char c = board[row][col];
                if (c == '.') {
                    continue;
                }
                if (++counts[c-'0'] >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
    bool check_rule3(const vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < 9; ++i) {
            int start_row = (i/3)*3;
            int start_col = (i%3)*3;
            int counts[10]{};
            for (int i = 0; i < 3; ++i) {
                int row = start_row + i; 
                for (int j = 0; j < 3; ++j) {
                    int col = start_col+j;
                    char c = board[row][col];
                    if (c == '.') {
                        continue;
                    }
                    if (++counts[c-'0'] >= 2) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return check_rule1(board) && check_rule2(board) && check_rule3(board);
    }
};

// Rule1: count every row and verify
// Rule2: count every column and verify
// Rule3: count every 9x9 and verify

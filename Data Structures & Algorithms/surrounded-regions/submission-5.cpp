class Solution {
    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = board.size();
        int n = board[0].size();

        board[r][c] = '#';
        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (!is_valid_rc(m, n, new_r, new_c)) {
                continue;
            }
            if (board[new_r][new_c] != 'O') {
                continue;
            }
            dfs(board, new_r, new_c);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        //1. do dfs started from edge 'O'
        int m = board.size();
        int n = board[0].size();
        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }
            if (board[r][n-1] == 'O') {
                dfs(board, r, n-1);
            }
        }
        for (int c = 1; c < n-1; ++c) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }
            if (board[m-1][c] == 'O') {
                dfs(board, m-1, c);
            }
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
                else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};

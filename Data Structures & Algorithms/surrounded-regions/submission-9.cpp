class Solution {
    using pii = pair<int,int>;
    static constexpr int dirs[4][2]{{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
public:
    void solve(vector<vector<char>>& board) {
        //1. collect all edge 'O' as sources
        int m = board.size();
        int n = board[0].size();
        queue<pii> que;
        for (int r = 0; r < m; ++r) {
            int c1 = 0;
            if (board[r][c1] == 'O') {
                board[r][c1] = '#';
                que.emplace(r, c1);
            }
            int c2 = n-1;
            if (board[r][c2] == 'O') {
                board[r][c2] = '#';
                que.emplace(r, c2);
            }
        }
        for (int c = 1; c < n-1; ++c) {
            int r1 = 0;
            if (board[r1][c] == 'O') {
                board[r1][c] = '#';
                que.emplace(r1, c);
            }
            int r2 = m-1;
            if (board[r2][c] == 'O') {
                board[r2][c] = '#';
                que.emplace(r2, c);
            }
        }
        //2. do bfs to update board
        // mark edge 'O' as '#' as visited
        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();

            for (const auto& dir : dirs) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (!is_valid_rc(m, n, new_r, new_c)) {
                    continue;
                }
                if (board[new_r][new_c] != 'O') {
                    continue;
                }
                board[new_r][new_c] = '#';
                que.emplace(new_r, new_c);
            }
        }
        //3. replace
        // '#' -> 'O'
        // 'O' -> 'X'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == '#') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};

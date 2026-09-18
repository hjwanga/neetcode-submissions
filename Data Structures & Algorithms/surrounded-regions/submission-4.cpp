class Solution {
    using pii = pair<int,int>;
    bool is_on_edge(int m, int n, int r, int c) {
        return r == m-1 || r == 0 || c == n-1 || c == 0;
    }

    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void dfs(const vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited, vector<pii>& one_island) {
        static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = board.size();
        int n = board[0].size();

        if (visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        one_island.emplace_back(r,c);
        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (!is_valid_rc(m, n, new_r, new_c)) {
                continue;
            }
            if (board[new_r][new_c] == 'O' && !visited[new_r][new_c]) {
                dfs(board, new_r, new_c, visited, one_island);
            }
        }
    }

    void get_islands(const vector<vector<char>>& board, vector<vector<pii>>& islands) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    vector<pii> one_island;
                    dfs(board, r, c, visited, one_island);
                    islands.push_back(one_island);
                }
            }
        }
    }

    void capture_surround(vector<vector<char>>& board, const vector<pii>& island) {
        int m = board.size();
        int n = board[0].size();
        // per island
        bool has_on_edge = false;
        for (const auto& [r, c] : island) {
            if (is_on_edge(m, n, r, c)) {
                has_on_edge = true;
                break;
            }
        }
        if (!has_on_edge) {
            for (const auto& [r, c] : island) {
                board[r][c] = 'X';
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // 1. get islands
        vector<vector<pii>> islands;
        get_islands(board, islands);

        // 2. check surround
        for (const vector<pii>& island : islands) {
            capture_surround(board, island);
        }
    }
};

// 1. 收集island
// 2. 確認每個island是否在邊上
//    有: surround
//  沒有: 取代為X
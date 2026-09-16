class Solution {
    bool dfs(const vector<vector<char>>& board, const string& word, int r, int c, int index, vector<vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        if (index == (int)word.size()) {
            return true;
        }
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }
        if (word[index] != board[r][c]) {
            return false;
        }
        if (visited[r][c]) {
            return false;
        }
        visited[r][c] = true;
        constexpr int dirs[4][2]{{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            bool one_sol = dfs(board, word, new_r, new_c, index+1, visited);
            if (one_sol) {
                return true;
            }
        }
        visited[r][c] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dfs(board, word, r, c, 0, visited)) {
                    return true;
                }        
            }
        }
        return false;
    }
};

// "CAC"
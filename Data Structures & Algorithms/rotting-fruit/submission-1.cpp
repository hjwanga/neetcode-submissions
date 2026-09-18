class Solution {
    static constexpr int EMPTY = 0;
    static constexpr int FRESH = 1;
    static constexpr int ROTTEN = 2;
    static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    using pii = pair<int,int>;

    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pii> que;
        int fresh_count = 0;
        // 1. push rotten
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == ROTTEN) {
                    que.emplace(r, c);
                } else if (grid[r][c] == FRESH) {
                    ++fresh_count;
                }
            }
        }

        // 2. BFS
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            int before = fresh_count;
            for (int i = 0; i < size; ++i) {
                auto [r, c] = que.front();
                que.pop();
                for (const auto& dir : dirs) {
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];
                    if (!is_valid_rc(m, n, new_r, new_c)) {
                        continue;
                    }
                    if (grid[new_r][new_c] != FRESH) {
                        continue;
                    }
                    fresh_count--;
                    grid[new_r][new_c] = ROTTEN;
                    que.emplace(new_r, new_c);
                }
            }
            int after = fresh_count;
            // No change in fresh fruit: break;
            if (before == after) {
                break;
            }
            ++result;
        }
        return fresh_count == 0 ? result : -1;
    }
};

// 1. push rotten fruit
// 2. do BFS

// [1 0 1]
// [0 2 0]
// [1 0 1]
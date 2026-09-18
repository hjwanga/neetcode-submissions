class Solution {
    static constexpr int LAND = 2147483647;
    static constexpr int CHEST = 0;
    static constexpr int WATER = -1;
    // <r, c, dist>
    using State = tuple<int,int,int>;
    static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // 1. append chest to que
        int m = grid.size();
        int n = grid[0].size();
        queue<State> que;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == CHEST) {
                    que.emplace(r, c, 0);
                }
            }
        }
        // 2. BFS
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c, dist] = que.front();
                que.pop();
                for (const auto& dir : dirs) {
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];
                    int new_dist = dist+1;
                    if (!is_valid_rc(m, n, new_r, new_c)) {
                        continue;
                    }
                    if (grid[new_r][new_c] != LAND) {
                        continue;
                    }
                    grid[new_r][new_c] = new_dist;
                    que.emplace(new_r, new_c, new_dist);
                }
            }
        }
    }
};

// L W C L
// L L L W
// L W L W
// C W L L

// 1. use chest as node to do BFS
// 2. once LAND != INT_MAX, which is visited, then return. BFS guarantees shortest dist

//  C 1 2 3 2 1
//  1 2 3 L 2 1 C

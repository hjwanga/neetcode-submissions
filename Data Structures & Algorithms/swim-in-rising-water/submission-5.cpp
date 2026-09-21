class Solution {
    using State = tuple<int,int,int>;
    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        static constexpr int dirs[4][2]{{1,0}, {0,1}, {-1,0}, {0,-1}};
        priority_queue<State, vector<State>, greater<State>> pq;

        int result = grid[0][0];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.emplace(grid[0][0], 0, 0);

        while (!pq.empty()) {
            auto [level, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;
            result = max(result, level);

            if (r == m-1 && c == n-1) {
                break;
            }

            for (const auto& dir : dirs) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (!is_valid_rc(m, n, new_r, new_c)) {
                    continue;
                }
                pq.emplace(grid[new_r][new_c], new_r, new_c);
            }
        }

        return result;
    }
};

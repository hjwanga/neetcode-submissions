class Solution {
    bool is_valid_rc(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void bfs(const vector<vector<int>>& heights, queue<pair<int,int>>& que, vector<vector<bool>>& visited) {
        static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = heights.size();
        int n = heights[0].size();
        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();

            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;

            for (const auto& dir : dirs) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (!is_valid_rc(m, n, new_r, new_c)) {
                    continue;
                }
                if (heights[r][c] <= heights[new_r][new_c]) {
                    que.emplace(new_r, new_c);
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int,int>> que_pacific;
        for (int c = 0; c < n; ++c) {
            que_pacific.emplace(0, c);
        }
        for (int r = 1; r < m; ++r) {
            que_pacific.emplace(r, 0);
        }
        queue<pair<int,int>> que_atlantic;
        for (int c = 0; c < n; ++c) {
            que_atlantic.emplace(m-1, c);
        }
        for (int r = 0; r < m-1; ++r) {
            que_atlantic.emplace(r, n-1);
        }
        vector<vector<bool>> visited_pacific(m, vector<bool>(n, false));
        vector<vector<bool>> visited_atlantic(m, vector<bool>(n, false));
        
        // Do BFS
        bfs(heights, que_pacific, visited_pacific);
        bfs(heights, que_atlantic, visited_atlantic);
        
        // Found overlapping
        vector<vector<int>> result;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (visited_pacific[r][c] && visited_atlantic[r][c]) {
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
};

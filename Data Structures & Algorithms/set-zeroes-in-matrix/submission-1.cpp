class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> points;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    points.emplace_back(r, c);
                }
            }
        }

        int k = points.size();
        for (int i = 0; i < k; ++i) {
            int point_r = points[i].first;
            int point_c = points[i].second;

            // ^ fixed point_c
            for (int r = point_r-1; r >= 0; --r) {
                matrix[r][point_c] = 0;
            }
            // v fixed point_c
            for (int r = point_r+1; r <= m-1; ++r) {
                matrix[r][point_c] = 0;
            }

            // < fixed point_r
            for (int c = point_c-1; c >= 0; --c) {
                matrix[point_r][c] = 0;
            }
            // > fixed point_r
            for (int c = point_c+1; c <= n-1; ++c) {
                matrix[point_r][c] = 0;
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 標註0 在r = 0 跟 c = 0
        // 標註row_0_all_zero 跟 col_0_all_zero
        int m = matrix.size();
        int n = matrix[0].size();
        bool row_0_all_zero = false;
        bool col_0_all_zero = false;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    if (r == 0) {
                        row_0_all_zero = true;
                    }
                    if (c == 0) {
                        col_0_all_zero = true;
                    }
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        // 處理[r][0]
        // 處理[0][c]
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        // 處理r == 0, c == 0
        if (row_0_all_zero) {
            for (int c = 0; c < n; ++c) {
                matrix[0][c] = 0;
            }
        }
        if (col_0_all_zero) {
            for (int r = 0; r < m; ++r) {
                matrix[r][0] = 0;
            }
        }
    }
};

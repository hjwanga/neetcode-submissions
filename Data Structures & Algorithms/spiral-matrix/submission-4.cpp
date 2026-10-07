class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int left = 0;
        int bottom = m-1;
        int right = n-1;
        vector<int> result;
        result.reserve(m*n);
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) {
                result.push_back(matrix[top][c]);
            }
            for (int r = top+1; r <= bottom; ++r) {
                result.push_back(matrix[r][right]);
            }
            if (top < bottom) {
                for (int c = right-1; c >= left; --c) {
                    result.push_back(matrix[bottom][c]);
                }
            }
            if (left < right) {
                for (int r = bottom-1; r >= top+1; --r) {
                    result.push_back(matrix[r][left]);
                }
            }

            ++top;
            ++left;
            --bottom;
            --right;
        }
        return result;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Step1: transform
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Step2: col swap
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};

// 1 2 3
// 4 5 6
// 7 8 9

// Transform
// 1 4 7
// 2 5 8
// 3 6 9

// col swap


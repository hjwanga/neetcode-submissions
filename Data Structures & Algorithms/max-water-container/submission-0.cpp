class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        for (int l = 0; l < n; ++l) {
            int lh = heights[l];
            for (int r = l+1; r < n; ++r) {
                int rh = heights[r];
                result = max(result, min(lh, rh)*(r-l));
            }
        }
        return result;
    }
};



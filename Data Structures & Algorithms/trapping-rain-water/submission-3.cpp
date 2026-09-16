class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        int l = 0;
        int r = n-1;
        int max_left = height[l];
        int max_right = height[r];
        while (l < r) {
            int h = 0;
            if (max_left < max_right) {
                ++l;
                h = max_left - height[l];
                max_left = max(max_left, height[l]);
            }
            else {
                --r;
                h = max_right - height[r];
                max_right = max(max_right, height[r]);
            }
            h = max(h, 0);
            result += h;
        }
        return result;
    }
};

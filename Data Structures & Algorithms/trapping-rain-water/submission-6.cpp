class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int left_max = height[0];
        int right_max = height[n-1];
        int result = 0;
        while (l < r) {
            if (left_max < right_max) {
                ++l;
                int h = height[l];
                int area = left_max - h;

                left_max = max(left_max, h);
                area = max(area, 0);
                result += area;
            }
            else {
                --r;
                int h = height[r];
                int area = right_max - h;

                right_max = max(right_max, h);
                area = max(area, 0);
                result += area;
            }
        }
        return result;
    }
};

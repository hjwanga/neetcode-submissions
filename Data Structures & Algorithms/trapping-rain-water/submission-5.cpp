class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // left_maxs[i] := the max height from 0 1 2 .. i-2 i-1 i
        // right_maxs[i] := the max height from i i+1 i+2 ..0 n-1 
        vector<int> left_maxs(n, 0);
        vector<int> right_maxs(n, 0);
        left_maxs[0] = height[0];
        right_maxs[n-1] = height[n-1];
        for (int i = 1; i < n; ++i) {
            left_maxs[i] = max(left_maxs[i-1], height[i]);
        }
        for (int i = n-2; i >= 0; --i) {
            right_maxs[i] = max(right_maxs[i+1], height[i]);
        }
        int result = 0;
        for (int i = 1; i < n-1; ++i) {
            int h = height[i];
            int area = min(left_maxs[i-1], right_maxs[i+1]) - h;
            area = max(area, 0);
            result += area;
        }
        return result;
    }
};

//   height  = [0,2,0,3,1,0,1,3,2,1]
// left_maxs = [0,2,2,3,3,3,3,3,3,3]
// right_maxs= [3,3,3,3,3,3,3,3,2,1]



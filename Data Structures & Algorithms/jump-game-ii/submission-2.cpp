class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        while (r < n-1) {
            int farthest = r;
            for (int i = l; i <= r; ++i) {
                farthest = max(farthest, i+nums[i]);
            }
            l = r+1;
            r = farthest;
            ++result;
        }
        return result;
    }
};

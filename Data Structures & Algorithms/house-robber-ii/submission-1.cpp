class Solution {
    int dfs(const vector<int>& nums, int l, int r) {
        int n = r-l+1;
        if (n == 1) {
            return nums[l];
        }
        if (n == 2) {
            return max(nums[l], nums[l+1]);
        }
        int dp_m2 = nums[l];
        int dp_m1 = max(nums[l], nums[l+1]);
        int dp = 0;
        for (int i = l+2; i <= r; ++i) {
            dp = max(dp_m2 + nums[i], dp_m1);
            dp_m2 = dp_m1;
            dp_m1 = dp;
        }
        return dp;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int l = 0;
        int r = n-1;
        int sol1 = dfs(nums, l, r-1);
        int sol2 = dfs(nums, l+1, r);
        return max(sol1, sol2);
    }
};

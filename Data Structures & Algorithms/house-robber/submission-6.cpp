class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int dp_m2 = nums[0];
        int dp_m1 = max(nums[0], nums[1]);
        int dp = 0;
        for (int i = 2; i < n; ++i) {
            dp = max(dp_m2 + nums[i], dp_m1);
            dp_m2 = dp_m1;
            dp_m1 = dp;
        }
        return dp;
    }
};

// dp[i] := 從第0間搶到到i間, 能夠拿到最多的錢是多少
// dp[i] = max(搶ith,不搶ith) = max(dp[i-2] + nums[i], dp[i-1])

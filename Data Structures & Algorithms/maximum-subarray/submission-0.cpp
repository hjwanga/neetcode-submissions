class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -10001);
        int result = dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            // 接續 或 重新開始
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

// dp[i] := nums[i]為結尾的max subarray sum
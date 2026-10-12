class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dpim1 = 0;
        int result = dpim1 = nums[0];
        for (int i = 1; i < n; ++i) {
            // 接續 或 重新開始
            int dp = max(nums[i], nums[i] + dpim1);
            result = max(result, dp);
            dpim1 = dp;
        }
        return result;
    }
};

// dp[i] := nums[i]為結尾的max subarray sum
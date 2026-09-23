class Solution {
    int dfs(const vector<int>& nums, int len, vector<int>& dp) {
        int r = len-1;
        if (r == 0) {
            return nums[r];
        }
        if (r == 1) {
            return max(nums[r], nums[r-1]);
        }
        if (dp[len] != -1) {
            return dp[len];
        }

        return dp[len] = max(dfs(nums, len-2, dp) + nums[r], dfs(nums, len-1, dp));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return dfs(nums, n, dp);
    }
};

// FAIL
// dp[i] := 搶第ith間, 能夠拿到最多的錢是多少
// dp[i] = nums[i] + dp[i-2];

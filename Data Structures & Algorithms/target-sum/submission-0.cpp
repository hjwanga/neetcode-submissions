class Solution {
    int dfs(const vector<int>& nums, int target, int index, vector<unordered_map<int,int>>& dp) {
        int n = nums.size();
        if (index == n) {
            return target == 0 ? 1 : 0;
        }
        if (dp[index].count(target)) {
            return dp[index][target];
        }

        // + index
        int op1 = dfs(nums, target + nums[index], index+1, dp);
        // - index
        int op2 = dfs(nums, target - nums[index], index+1, dp);
        return dp[index][target] = op1 + op2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        return dfs(nums, target, 0, dp);
    }
};



// [1,1] => 2
// +1 -1
// -1 +1

// 1. dfs(nums, i, target)
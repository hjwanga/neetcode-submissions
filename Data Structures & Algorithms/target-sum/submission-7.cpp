class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum+target)%2 || abs(target) > sum) {
            return 0;
        }
        int capacity = (sum + target)/2;
        // dp[i][j] := nums[0..i],能湊出和=j,的組合有幾種
        //               不選 nums[i] + 選 nums[i]
        // dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        dp[0][0] = 1;
        if (nums[0] < (int)dp[0].size()) {
            dp[0][nums[0]] += 1;
        }
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = capacity; j >= 0; --j) {
                dp[i][j] = dp[i-1][j]; // 不選nums[i]
                if (j-num >= 0) {
                    dp[i][j] += dp[i-1][j-num]; // 選nums[i]
                }
            }
        }
        return dp[n-1][capacity];
    }
};
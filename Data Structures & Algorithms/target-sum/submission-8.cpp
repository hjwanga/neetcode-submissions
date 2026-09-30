class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum+target)%2 || abs(target) > sum) {
            return 0;
        }
        int capacity = (sum + target)/2;
        // dp[j] := nums[0..i],能湊出和=j,的組合有幾種
        //               不選 nums[i] + 選 nums[i]
        // dp[j] = dp[j] + dp[j-nums[i]]
        int n = nums.size();
        vector<int> dp(capacity+1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = capacity; j >= num; --j) {
                //      不選  +  選
                dp[j] = dp[j] + dp[j-num];
            }
        }
        return dp[capacity];
    }
};
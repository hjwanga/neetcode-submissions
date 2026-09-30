class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum+target)%2 || abs(target) > sum) {
            return 0;
        }
        int capacity = (sum+target)/2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

        dp[0][0] = 1;
        if (nums[0] < (int)dp[0].size()) {
            dp[0][nums[0]] += 1;
        }
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = capacity; j >= 0; --j) {
                int dp_im1_jmnum = j-num >= 0 ? dp[i-1][j-num] : 0;
                dp[i][j] = dp[i-1][j] + dp_im1_jmnum;
            }
        }
        return dp[n-1][capacity];
    }
};

// dp[i][j] := 在可以選前i項的情況, 且和剛好為j的組合有幾種

//                 不選 || 選
// dp[i][j] = dp[i-1][j] + dp[i-1][j-w]

//          0 1 2
//  nums = [2,2,2], target = 2. capacity = 4
//
//  i\j 0 1 2 3 4
//   0  1 0 1 0 0       
//   1
//   2
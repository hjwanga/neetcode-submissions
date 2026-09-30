class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum%2) {
            return false;
        }
        const int n = nums.size();
        const int capacity = total_sum/2;
        vector<vector<bool>> dp(n, vector<bool>(capacity+1, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        // i == 0 case
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = capacity; j >= num; --j) {
                           // 不選 || 選 第i項
                dp[i][j] = dp[i-1][j] || dp[i-1][j-num];
            }
        }

        return dp[n-1][capacity];
    }
};

// 0-1 背包問題
// dp[i][j] := 使用前i個物品, 在背包容量j的情況下, 能否塞滿?
//1. total_sum 必定要偶數
//2. 背包容量 = total_sum / 2
//3. 物品重量 = nums[i]
// dp[i][j] = 用第i個, 不用第i個

// [2 2 3 5] n = 4, capacity = 6
//   0 1 2 3 4 5 6
// 0 T F T F F F F
// 1 T
// 2 T
// 3 T
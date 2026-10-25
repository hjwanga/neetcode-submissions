class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n+2, 1);
        for (int i = 0; i < n; ++i) {
            new_nums[i+1] = nums[i];
        }

        int m = new_nums.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i+len-1 <= m-2; ++i) {
                int j = i+len-1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + new_nums[i-1]*new_nums[k]*new_nums[j+1]);
                }
            }
        }
        return dp[1][m-2];
    }
};

//   nums =     [?,?,?,?]
// new_nums = [1,?,?,?,?,1]
//             0  ..    m-1
// dp[i][j] := 給定k為最後一個氣球情況下,
// dp[i][j] = dp[i][k] + dp[k][j] + nums[k-1]*nums[k]*nums[k+1] 
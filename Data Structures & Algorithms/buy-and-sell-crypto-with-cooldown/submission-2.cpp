class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] -= prices[0];
        dp[0][3] = INT_MIN;
        for (int i = 1; i < n; ++i) {
            // buy
            int dp_im2_1 = i-2 >= 0 ? dp[i-2][1] : 0;
            dp[i][0] = max(dp_im2_1, dp[i-1][2]) - prices[i];
            // sell
            dp[i][1] = max(dp[i-1][0], dp[i-1][3]) + prices[i];
            // pass
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = max(dp[i-1][0], dp[i-1][3]);
        }
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3]});
    }
};

// Input: prices = [1,3,4,0,4]
// i                ^
// 買 | 不買
// 賣 | 不賣 -> 影響下一次可以買的時間

// 第i天 Buy -> 第i-2天 Sell, 第i-1天空手
// 第i天 Sell -> 第i-1天 Buy, 第i-1天持有
// 第i天 空手pass -> 第i-1天Sell, 第i-1天空手pass
// 第i天 持有pass -> 第i-1天Buy, 第i-1天持有pass

// dp[i][4]: 第i天, 目前的profit
// dp[i][0]: 第i天 買
// dp[i][1]: 第i天 賣
// dp[i][2]: 第i天 無coin pass
// dp[i][3]: 第i天 有coin pass
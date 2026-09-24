class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // [amount]
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            int best_choise = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int coin = coins[j];
                if (coin > i) {
                    continue;
                }
                if (dp[i-coin] != INT_MAX) {
                    best_choise = min(best_choise, 1 + dp[i-coin]);
                }
            }
            dp[i] = best_choise;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// for 0 : amount
//   for coin : coins

// dp[i] := 在amount i, 硬幣能用coins[0,n-1]的情況下, 最少需要多少枚

// coins = [1,5,10]
//    0 1 2 3 4 5 6 7 8 9 10 11 12
// dp 0 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; ++j) {
            int coin = coins[j];
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
// 2. DP
// dp[i] := amount i的情況下, 能使用coins[0..n-1]湊出amount的總數

// for amount
//    for coins
//  coins = [1,2,3]
//   i = 0 1 2 3 4 
//dp[i]= 1 1 2 4 

// 1: [1]
// 2: [1,1] | [2]
// 3: [1,1,1] [2,1] | [1,2]


// coins = [1,2,3]
//    i = 0 1 2 3 4
// dp[i]= 1 1 1 1 1  j = 0
// dp[i]= 1 1 2 2 3  j = 1
// dp[i]= 1 1 2 3 4  j = 2
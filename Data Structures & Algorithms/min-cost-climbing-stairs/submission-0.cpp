class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // reach to index n
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};

//  0 1 2 3
// [1 2 3]

// dp[i] := 走到第ith, 最少要花多少錢
// dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
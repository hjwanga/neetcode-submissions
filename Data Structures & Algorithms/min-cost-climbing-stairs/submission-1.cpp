class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp_m2 = 0;
        int dp_m1 = 0;
        int dp = 0;
        for (int i = 2; i <= n; ++i) {
            dp = min(dp_m1 + cost[i-1], dp_m2 + cost[i-2]);
            dp_m2 = dp_m1;
            dp_m1 = dp;
        }
        return dp;
    }
};

//  0 1 2 3
// [1 2 3]

// dp[i] := 走到第ith, 最少要花多少錢
// dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
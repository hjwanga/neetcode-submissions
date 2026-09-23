class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


// 2
// -> 1 + 1
// -> 2

// 3
// -> 1 + 1 + 1
// -> 1 + 2
// -> 2 + 1

// climbStairs[n] = climbStairs[n-1] + climbStairs[n-2]
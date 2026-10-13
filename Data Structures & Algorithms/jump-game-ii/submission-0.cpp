class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        constexpr int INIT = 1e9;
        vector<int> dp(n, INIT);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = min(i + nums[i], n-1); j > i; --j) {
                if (dp[j] == INIT) {
                    dp[j] = dp[i] + 1;
                } else {
                    break;
                }
            }
        }
        return dp[n-1];
    }
};

// dp[i] := ith 所需要的最少步數
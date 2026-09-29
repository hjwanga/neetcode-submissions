class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum%2) {
            return false;
        }
        const int n = nums.size();
        const int capacity = total_sum/2;
        vector<bool> dp(capacity+1, false);
        dp[0] = true;
        
        for (int j = 0; j < n; ++j) {
            int w = nums[j];
            for (int cap = capacity; cap >= 1; --cap) {
                if (w > cap) {
                    break;
                }
                // 不選 || 選 第j項
                dp[cap] = dp[cap] || dp[cap-w];
            }
        }
        return dp[capacity];

        // for (int cap = 1; cap <= capacity; ++cap) {
        //     for (int j = 0; j < n; ++j) {
        //         if (dp[cap][j]) {
        //             continue;
        //         }
        //         int w = nums[j];
        //         if (w > cap) {
        //             continue;
        //         }
        //         if (j-1 >= 0) {
        //             // 不選 || 選 第j項
        //             dp[cap][j] = dp[cap][j-1] || dp[cap-w][j-1];
        //         }
        //     }
        // }

        // return dp[capacity][n-1];
    }
};

// 0-1 背包問題
// dp[i][j] := 容量i, 物品能選[0...j]的情況下, 能否裝滿背包?  
//1. total_sum 必定要偶數
//2. 背包容量 = total_sum / 2
//3. 物品重量 = nums[i]

// 1-D
// dp[i] := 容量i, 物品能選[0...j]的情況下, 能否裝滿背包?  

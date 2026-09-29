class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int num : nums) {
            // do lower_bound
            int m = dp.size();
            int target_pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            if (target_pos == m) {
                dp.push_back(num);
            } else {
                dp[target_pos] = num;
            }
        }
        return (int)dp.size();
    }
};

// dp[i] := 長度為i的LIS, 尾數最小是多少


// nums = [9,1,4,2,3,3,7]
//                  ^
// [1]: 1
// [2]: 2
// [3]: 3
// [4]: 7
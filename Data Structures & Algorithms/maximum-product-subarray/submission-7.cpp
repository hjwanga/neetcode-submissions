class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int result = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            if (num < 0) {
                swap(curr_max, curr_min);
            }
            curr_max = max(num, num*curr_max);
            curr_min = min(num, num*curr_min);
            result = max(result, curr_max);
        }
        return result;
    }
};
//      [2 4 -3 5]
// pos : 2 8 
// neg : X X
// result = 8
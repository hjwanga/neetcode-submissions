class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int result = nums[0];
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            if (result == num) {
                ++count;
            } else {
                --count;
                // switch to new num
                if (count == 0) {
                    count = 1;
                    result = num;
                }
            }
        }
        return result;
    }
};
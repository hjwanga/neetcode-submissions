class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // sort in ascending order
        sort(nums.begin(), nums.end());

        // count consecutive length, if not, reset to 1
        int result = 1;
        int count = 1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                continue;
            }

            if (nums[i]-1 == nums[i-1]) {
                ++count;
            }
            else {
                count = 1;
            }
            result = max(result, count);
        }
        return result;
    }
};

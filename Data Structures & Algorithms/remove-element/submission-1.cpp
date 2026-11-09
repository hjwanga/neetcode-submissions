class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int result = 0;

        // swap to the r
        int r = n-1;
        for (int l = 0, r = n-1; l <= r;) {
            if (nums[l] != val) {
                ++result;
                ++l;
            } else {
                swap(nums[l], nums[r]);
                --r;
            }
        }

        return result;
    }
};
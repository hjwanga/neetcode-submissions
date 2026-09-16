class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int last = nums[r];
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] <= last) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return nums[l];
    }
};

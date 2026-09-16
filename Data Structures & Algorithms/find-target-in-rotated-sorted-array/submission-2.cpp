class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int last = nums[r];
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                return mid;
            }
            // left region: 0
            // right region: 1
            // 0000111111
            // right region
            if (nums[mid] < last) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            // left region
            else {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};


//        0 1 2 3 4 5 
// nums: [3,4,5,6,1,2]
// l = 0, r = 5, mid = 2, last = 2, target = 1
// nums[mid] = 5 > last = 2 -> l = mid+1 = 3
// l = 3, r = 5, mid = 4, last = 2, target = 1
// nums[mid] = 1,
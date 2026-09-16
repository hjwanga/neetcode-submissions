class Solution {
public:
    int findMin(vector<int> &nums) {
        // 1.取mid 看他是屬於左邊還是右邊
        // case1:
        //     6
        //   5
        // 4
        //            3
        //          2
        //        1

        // case2:
        //      6
        //     5
        //    4
        //   3
        //  2
        // 1
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int result = 1e5;
        while (l <= r) {
            int l_num = nums[l];
            int r_num = nums[r];
            if (l_num < r_num) {
                result = min(result, l_num);
                break;
            }

            int mid = l + (r-l)/2;
            int mid_num = nums[mid];
            result = min(result, mid_num);
            // case1
            if (l_num <= mid_num) {
                l = mid+1;
            }
            // case2
            else {
                r = mid-1;
            }
        }
        return result;
    }
};

//[0 1 2 3 4 5]
// 4 5 0 1 2 3 
// l = 0, r = 5, mid = 2
//     4      3        0
// 
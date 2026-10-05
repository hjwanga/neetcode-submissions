class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i && nums[i] != -1) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        int result = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == -1) {
                result = i;
                break;
            }
        }
        return result;
    }
};

//       0 1 2 3
// nums [1,-1,0,2]
//       ^
//      -1 1  0 2
//            ^
//       0 1 -1 2
//              ^
//       0 1  2 -1
//              ^
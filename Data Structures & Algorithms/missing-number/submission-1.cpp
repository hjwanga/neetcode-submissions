class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        for (int i = 0; i < n; ++i) {
            result ^= (nums[i] ^ i);
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

//         0 1 2
// nums = [1,0,3]
// index 0,1,2
// num   0 1 3
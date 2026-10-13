class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest_index = 0;
        for (int i = 0; i < n; ++i) {
            if (i > farthest_index) {
                return false;
            }
            farthest_index = max(farthest_index, i+nums[i]);
        }
        return farthest_index >= n-1;
    }
};
// 最遠的index
// 如果 i > 最遠的index : return false;
// 如果 最遠的index >= n-1 :  return true;
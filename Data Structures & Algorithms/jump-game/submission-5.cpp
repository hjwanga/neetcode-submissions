class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                return false;
            }
            int move = nums[i];
            for (int j = i+move; j > i; --j) {
                if (j >= n-1) {
                    return true;
                }
                if (visited[j]) {
                    break;
                }
                visited[j] = true;
            }
        }
        return true;
    }
};
// 向前跳 再往回
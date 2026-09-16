class Solution {
    void dfs(const vector<int>& nums, int target, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        int n = nums.size();
        if (start >= n || target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(one_sol);
            return;
        }
        // 選 start
        one_sol.push_back(nums[start]);
        dfs(nums, target-nums[start], start, one_sol, result);
        one_sol.pop_back();
        // 不選 start
        dfs(nums, target, start+1, one_sol, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(nums, target, 0, one_sol, result);
        return result;
    }
};

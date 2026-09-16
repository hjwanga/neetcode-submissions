class Solution {
    void dfs(const vector<int>& nums, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        int n = nums.size();
        if (start >= n) {
            result.push_back(one_sol);
            return;
        }
        // 選
        one_sol.push_back(nums[start]);
        dfs(nums, start+1, one_sol, result);
        // 不選
        one_sol.pop_back();
        dfs(nums, start+1, one_sol, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(nums, 0, one_sol, result);
        return result;
    }
};

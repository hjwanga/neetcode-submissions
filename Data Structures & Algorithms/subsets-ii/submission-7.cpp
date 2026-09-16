class Solution {
    void dfs(const vector<int>& nums, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        result.push_back(one_sol);
        int n = nums.size();
        if (start >= n) {
            return;
        }

        for (int i = start; i < n; ++i) {
            if (i > start && nums[i-1] == nums[i]) {
                continue;
            }
            one_sol.push_back(nums[i]);
            dfs(nums, i+1, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(nums, 0, one_sol, result);
        return result;
    }
};

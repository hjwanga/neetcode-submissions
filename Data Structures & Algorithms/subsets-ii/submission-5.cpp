class Solution {
    void dfs(const vector<int>& nums, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        result.push_back(one_sol);
        int n = nums.size();
        if (start >= n) {
            return;
        }
        for (int i = start; i < n; ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            one_sol.push_back(nums[i]);
            dfs(nums, i+1, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 小到大
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(nums, 0, one_sol, result);
        return result;
    }
};

// [1,2,3]
//level0                []
//level1 [1]            [2]        [3]
//level2 [1,2]   [1,3]  [2,3]
//level3 [1,2,3]

// [1,1,2]
// level0              []
// level1 [1]                 [2]
// level2 [1,1] [1,2]
// level3 [1,1,2] 
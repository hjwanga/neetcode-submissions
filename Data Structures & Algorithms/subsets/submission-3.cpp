class Solution {
    void dfs(const vector<int>& nums, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        result.push_back(one_sol);
        int n = nums.size();
        if (start == n) {
            return;
        }
        for (int i = start; i < n; ++i) {
            one_sol.push_back(nums[i]);
            dfs(nums, i+1, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(nums, 0, one_sol, result);
        return result;
    }
};
// [1,2,3]

//level0 ->                    []
//level1 ->       [1]         [2]         [3]
//level2 ->   [1,2] [1,3]    [2,3]
//level3 -> [1,2,3]


// one_sol: [1,2,3]
// result: [[], [1], [1,2],]
// start = 3


class Solution {
    void dfs(const vector<int>& nums, int target, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(one_sol);
            return;
        }

        int n = nums.size();
        if (start >= n || target < 0) {
            return;
        }
        for (int i = start; i < n; ++i) {
            // early return
            if (nums[i] > target) {
                break;
            }
            one_sol.push_back(nums[i]);
            dfs(nums, target-one_sol.back(), i, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // 由小到大
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(nums, target, 0, one_sol, result);
        return result;
    }
};

//                                   
//level0                                          []
//level1            2                  5                     6            9
//level2 [2,2] [2,5] [2,6] [2,9]  [5,5] [5,6] [5,9]     [6,6] [6,9]      [9,9]
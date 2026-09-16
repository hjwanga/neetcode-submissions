class Solution {
    void dfs(const vector<int>& candidates, int target, int start, vector<int>& one_sol, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(one_sol);
            return;
        }

        int n = candidates.size();
        if (start >= n || target < 0) {
            return;
        }

        for (int i = start; i < n; ++i) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            one_sol.push_back(candidates[i]);
            dfs(candidates, target-one_sol.back(), i+1, one_sol, result);
            one_sol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(candidates, target, 0, one_sol, result);
        return result;
    }
};

// [1,2,2,4,5,6,9]
//level0                                                          []
//level1 [1]                              [2]                             [4]                   [5]              [6]       [9]
//level2 [1,2] [1,4] [1,5] [1,6] [1,9]    [2,2] [2,4] [2,5] [2,6] [2,9]   [4,5] [4,6] [4,9]     [5,6] [5,9]      [6,9]
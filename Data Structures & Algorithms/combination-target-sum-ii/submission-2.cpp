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
        // 選
        one_sol.push_back(candidates[start]);
        dfs(candidates, target-candidates[start], start+1, one_sol, result);
        one_sol.pop_back();
        // 不選
        int next = start+1;
        while (next < n && candidates[start] == candidates[next]) {
            ++next;
        }
        dfs(candidates, target, next, one_sol, result);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> result;
        vector<int> one_sol;
        dfs(candidates, target, 0, one_sol, result);
        return result;
    }
};

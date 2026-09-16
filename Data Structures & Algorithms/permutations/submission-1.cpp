class Solution {
    void dfs(const vector<int>& nums, int level, vector<bool>& visited, vector<int>& one_sol, vector<vector<int>>& result) {
        int n = nums.size();
        if (level >= n) {
            result.push_back(one_sol);
            return;
        }
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            one_sol.push_back(num);
            dfs(nums, level+1, visited, one_sol, result);
            one_sol.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> one_sol;
        vector<bool> visited(n, false);
        dfs(nums, 0, visited, one_sol, result);
        return result;
    }
};

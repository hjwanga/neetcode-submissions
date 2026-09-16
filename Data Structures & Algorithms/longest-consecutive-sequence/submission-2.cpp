class Solution {

    // return the # of element in this island
    int dfs(int node, unordered_set<int>& visited, unordered_set<int>& cache) {
        if (!cache.count(node)) {
            return 0;
        }
        if (visited.count(node)) {
            return 0;
        }
        visited.insert(node);
        // try node-1
        int lhs = dfs(node-1, visited, cache);
        // try node+1
        int rhs = dfs(node+1, visited, cache);
        return lhs + 1 + rhs;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache;
        for (int num : nums) {
            cache.insert(num);
        }

        // found connectivity
        int result = 0;
        unordered_set<int> visited;
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            int node = *it;
            if (visited.count(node)) {
                continue;
            }
            int len = dfs(node, visited, cache);
            result = max(result, len);
        }
        return result;
    }
};

// cache [2,3,4]
// visited [2 3 4]

// 3 2 4
// ^
// lhs:  dfs(2)
// rhs:  dfs(4)

// dfs(3) = dfs(2) + 1 + dfs(4)
//   dfs(2) = 0 + 1 + 0
//   dfs(4) = 0 + 1 + 0


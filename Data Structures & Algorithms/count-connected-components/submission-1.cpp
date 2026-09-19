class Solution {
    void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (int next_node : graph[node]) {
            dfs(graph, next_node, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // 1. build graph
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& edge : edges) {
            int src = edge[0];
            int tgt = edge[1];
            graph[src].push_back(tgt);
            graph[tgt].push_back(src);
        }

        // 2. dfs to collect island
        int result = 0;
        for (int node = 0; node < n; ++node) {
            if (visited[node]) {
                continue;
            }
            ++result;
            dfs(graph, node, visited);
        }
        return result;
    }
};

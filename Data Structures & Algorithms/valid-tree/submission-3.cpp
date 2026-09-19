class Solution {
    void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;

        for (const auto& next_node : graph[node]) {
            dfs(graph, next_node, visited);
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // constraint 1:
        int m = edges.size();
        if (n-1 != m) {
            return false;
        }
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& edge : edges) {
            int src = edge[0];
            int tgt = edge[1];
            graph[src].push_back(tgt);
            graph[tgt].push_back(src);
        }

        // constraint 2:
        // island = 1 -> visited count should equal to n
        dfs(graph, 0, visited);
        int visited_count = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ++visited_count;
            }
        }
        return visited_count == n;
    }
};

// tree
// 1. node: n. edge: n-1
// 2. all connected: island = 1
//   0  -  1   3
//    \  /
//      2



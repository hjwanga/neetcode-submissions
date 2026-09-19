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
        int land_count = 0;
        for (int node = 0; node < n; ++node) {
            if (visited[node]) {
                continue;
            }
            dfs(graph, node, visited);

            if (++land_count > 1) {
                break;
            }
        }
        return land_count == 1;
    }
};

// tree
// 1. node: n. edge: n-1
// 2. all connected: island = 1
//   0  -  1   3
//    \  /
//      2

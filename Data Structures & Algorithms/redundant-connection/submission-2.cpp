class Solution {
public:
    // node is 1-based
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 1. get n
        int n = 0;
        for (const auto& edge : edges) {
            n = max({n, edge[0], edge[1]});
        }

        // 2. use topological sort to remove leaf
        vector<bool> removed(n+1, false);
        vector<int> incomings(n+1, 0);
        vector<vector<int>> graph(n+1, vector<int>());
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            incomings[node1]++;
            incomings[node2]++;
        }
        // 3. push incoming 1 to queue
        queue<int> que;
        for (int node = 1; node <= n; ++node) {
            if (incomings[node] == 1) {
                removed[node] = true;
                que.push(node);
            }
        }

        // 4. do BFS
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (int next_node : graph[node]) {
                if (removed[next_node]) {
                    continue;
                }
                if (--incomings[next_node] == 1) {
                    removed[next_node] = true;
                    que.push(next_node);
                }
            }
        }
        
        // 5. unremoved node is in a loop
        int m = edges.size();
        for (int i = m-1; i >= 0; --i) {
            const vector<int>& edge = edges[i];
            int node1 = edge[0];
            int node2 = edge[1];
            if (!removed[node1] && !removed[node2]) {
                return {node1, node2};
            }
        }
        return {};
    }
};

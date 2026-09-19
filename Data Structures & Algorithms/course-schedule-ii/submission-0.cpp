class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. collect incomings and build graph
        const int n = numCourses;
        vector<int> incomings(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (const vector<int>& edge : prerequisites) {
            int src = edge[1];
            int tgt = edge[0];
            incomings[tgt]++;
            graph[src].push_back(tgt);
        }

        // 2. collect incoming == 0 as sources
        queue<int> que;
        for (int node = 0; node < n; ++node) {
            if (incomings[node] == 0) {
                que.push(node);
            }
        }

        // 3. do bfs
        vector<int> result;
        result.reserve(n);
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            result.push_back(node);

            for (const auto& next_node : graph[node]) {
                if (--incomings[next_node] == 0) {
                    que.push(next_node);
                }
            }
        }

        // 4. check result.size() == n
        return (int)result.size() == n ? result : vector<int>();
    }
};

// 0 -> 1 | 2

// 2 - > 1 -> 0
// ^-----------
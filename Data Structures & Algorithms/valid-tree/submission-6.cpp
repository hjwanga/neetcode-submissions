class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if (n == 1) {
            return n-1 == m;
        }
        // constraint 1:
        if (n-1 != m) {
            return false;
        }

        // collect incoming == 1 as sources
        vector<int> incomings(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& edge : edges) {
            int src = edge[0];
            int tgt = edge[1];
            incomings[src]++;
            incomings[tgt]++;
            graph[src].push_back(tgt);
            graph[tgt].push_back(src);
        }

        // push incoming == 1 into queue
        vector<bool> visited(n, false);
        int visited_count = 0;
        queue<int> que;
        for (int node = 0; node < n; ++node) {
            if (incomings[node] == 1) {
                que.push(node);
                visited[node] = true;
                visited_count++;
            }
        }

        // constraint 2:
        // island = 1 -> visited count == n
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (const auto& next_node : graph[node]) {
                if (visited[next_node]) {
                    continue;
                }
                visited[next_node] = true;
                visited_count++;
                if (--incomings[next_node] == 1) {
                    que.push(next_node);
                }
            }
        }
        return visited_count == n;
    }
};

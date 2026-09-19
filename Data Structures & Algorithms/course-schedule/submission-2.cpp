class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. collect incoming
        const int n = numCourses;
        vector<int> incomings(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (const vector<int>& edge : prerequisites) {
            int src = edge[1];
            int tgt = edge[0];
            incomings[tgt]++;
            graph[src].push_back(tgt);
        }
        // 2. push incoming == 0 to que
        queue<int> que;
        for (int node = 0; node < n; ++node) {
            if (incomings[node] == 0) {
                que.push(node);
            }
        }
        // 3. do bfs
        int node_count = 0;
        while (!que.empty()) {
            int node = que.front();
            node_count++;
            que.pop();

            for (const auto& next_node : graph[node]) {
                if (--incomings[next_node] == 0) {
                    que.push(next_node);
                }
            }
        }
        return node_count == n;
    }
};

// prerequisites[i] = [a,b]
// 先做b 才能做a
// b->a

// intuition: topological sort

// [0, 1] [1, 2] [1 3]

// 3 -> 1 -> 0
//      ^
//      2
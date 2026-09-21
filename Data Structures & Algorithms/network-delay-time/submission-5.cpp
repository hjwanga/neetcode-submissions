class Solution {
    using pii = pair<int,int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Dijkstra - signle source K to other nodes: dist[1:n]
        // graph[u] = {v, t}
        vector<vector<pii>> graph(n+1, vector<pii>());
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            graph[u].emplace_back(v, t);
        }
        // NOTE1: use max to init
        vector<int> dists(n+1, INT_MAX);
        // <dist, node>
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dists[k] = 0;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();

            if (t > dists[node]) {
                continue;
            }
            
            for (const auto& neighbor : graph[node]) {
                int next_node = neighbor.first;
                int next_t = neighbor.second;
                if (t + next_t < dists[next_node]) {
                    dists[next_node] = t + next_t;
                    pq.emplace(dists[next_node], next_node);
                }
            }
        }

        // 2. return max(dist[1:n])
        int result = -1;
        for (int node = 1; node <= n; ++node) {
            if (dists[node] == INT_MAX) {
                return -1;
            }
            result = max(result, dists[node]);
        }
        return result;
    }
};

// 1-based node
//            0 1   2   3   4
// dists = [INF,0,  1,  2,  3]
//  pq: 

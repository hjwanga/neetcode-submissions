class Solution {
    // <distance, index of points>
    using State = pair<int,int>;
    int get_dist(const vector<int>& p1, const vector<int>& p2) {
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        return abs(x1-x2) + abs(y1-y2);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim
        int n = points.size();
        vector<int> visited(n, false);
        int result = 0;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            result += dist;

            for (int next_node = 0; next_node < n; ++next_node) {
                if (visited[next_node] || next_node == node) {
                    continue;
                }
                pq.emplace(get_dist(points[node], points[next_node]), next_node);
            }
        }
        return result;
    }
};

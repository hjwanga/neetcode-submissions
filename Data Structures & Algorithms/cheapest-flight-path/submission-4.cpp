class Solution {
    using pii = pair<int,int>;
    using State = tuple<int,int,int>;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Dijkstra
        // [src] = <tgt, price>
        vector<vector<pii>> graph(n);
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].emplace_back(to, price);
        }
        // <price, edge_count, node>
        priority_queue<State, vector<State>, greater<State>> pq;
        // [node][edge_count]
        vector<vector<int>> min_prices(n, vector<int>(k+2, INT_MAX));
        min_prices[src][0] = 0;
        pq.emplace(min_prices[src][0], 0, src);
        while (!pq.empty()) {
            auto [price, edge_count, node] = pq.top();
            pq.pop();

            // one more condition: K stops
            if (node == dst && edge_count-1 <= k) {
                return price;
            }

            if (price > min_prices[node][edge_count] || edge_count > k) {
                continue;
            }

            for (const auto& [next_node, price_curr_to_next] : graph[node]) {
                int next_edge_count = edge_count+1;
                if (price + price_curr_to_next < min_prices[next_node][next_edge_count]) {
                    min_prices[next_node][next_edge_count] = price + price_curr_to_next;
                    pq.emplace(min_prices[next_node][next_edge_count], next_edge_count, next_node);
                }
            }
        }
        return -1;
    }
};
//PR fromi != toi pricei 
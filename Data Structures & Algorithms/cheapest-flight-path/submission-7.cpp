class Solution {
    using pii = pair<int,int>;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // movement: k++
        k++;
        // [from] = <to, price>
        vector<vector<pii>> graph(n);
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].emplace_back(to, price);
        }

        // <node, price>
        vector<int> min_prices(n, INT_MAX);
        queue<pii> que;
        int move = 0;
        min_prices[src] = 0;
        que.emplace(src, min_prices[src]);
        while (!que.empty() && move <= k) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [node, price] = que.front();
                que.pop();
                if (price > min_prices[node]) {
                    continue;
                }
                min_prices[node] = price;
                for (const auto& [next_node, price_curr_to_next] : graph[node]) {
                    que.emplace(next_node, price+price_curr_to_next);
                }
            }
            ++move;
        }
        return min_prices[dst] == INT_MAX ? -1 : min_prices[dst];
    }
};

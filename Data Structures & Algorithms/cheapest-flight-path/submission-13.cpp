class Solution {
    using pii = pair<int,int>;
    using State = tuple<int,int,int>;
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

        // [node][move] = price
        vector<vector<int>> min_prices(n, vector<int>(k+1, INT_MAX));
        // <price, node, move>
        priority_queue<State, vector<State>, greater<State>> pq;
        min_prices[src][0] = 0;
        pq.emplace(min_prices[src][0], src, 0);

        while (!pq.empty()) {
            auto [price, node, move] = pq.top();
            pq.pop();
            if (node == dst) {
                return price;
            }
            // lazy remove
            if (price > min_prices[node][move]) {
                continue;
            }
            if (move == k) {
                continue;
            }

            for (const auto& [next_node, price_curr_to_next] : graph[node]) {
                int next_move = move+1;
                if (price+price_curr_to_next < min_prices[next_node][next_move]) {
                    min_prices[next_node][next_move] = price+price_curr_to_next;
                    pq.emplace(min_prices[next_node][next_move], next_node, next_move);
                }
            }
        }
        return -1;
    }
};

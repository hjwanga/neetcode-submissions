class Solution {
    void dfs(const string& start, unordered_map<string, vector<string>>& graph, vector<string>& result) {
        vector<string>& tos = graph[start];
        while (!tos.empty()) {
            string next_node = tos.back();
            tos.pop_back();
            dfs(next_node, graph, result);
        }
        // 代表這個node已經沒有其他edge需要尋訪了. 功成身退
        result.push_back(start);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //1. sort tickets using greater to easily pop
        sort(tickets.begin(), tickets.end(), greater<vector<string>>());
        //2. build graph
        unordered_map<string, vector<string>> graph;
        for (const auto& ticket : tickets) {
            const string& src = ticket[0];
            const string& tgt = ticket[1];
            graph[src].push_back(tgt);
        }

        vector<string> result;
        dfs("JFK", graph, result);
        reverse(result.begin(), result.end());
        return result;
    }
};

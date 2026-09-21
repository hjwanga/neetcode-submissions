class Solution {
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
        stack<string> stk;
        stk.push("JFK");

        vector<string> result;
        while (!stk.empty()) {
            string node = stk.top();

            vector<string>& tos = graph[node];
            if (tos.empty()) {
                result.push_back(node);
                stk.pop();
            } else {
                stk.push(tos.back());
                tos.pop_back();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

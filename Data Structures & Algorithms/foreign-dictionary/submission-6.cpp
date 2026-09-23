class Solution {
    bool build_graph(const string& word1, const string& word2, vector<vector<int>>& graph) {
        int m = word1.size();
        int n = word2.size();
        int len = min(m, n);
        for (int i = 0; i < len; ++i) {
            char c1 = word1[i];
            char c2 = word2[i];
            if (c1 == c2) {
                continue;
            }
            graph[c1-'a'].push_back(c2-'a');
            return true;
        }
        // Q: why m <= n instead of m < n?
        // A: see case below
        // case: ["a", "a"]
        // return "a"
        return m <= n;
    }
public:
    string foreignDictionary(vector<string>& words) {
        // build graph: edge is the order
        int n = words.size();
        vector<vector<int>> graph(26);
        for (int i = 1; i < n; ++i) {
            const string& word1 = words[i-1];
            const string& word2 = words[i];
            if (!build_graph(word1, word2, graph)) {
                return "";
            }
        }

        // topological sort
        queue<int> que;
        vector<int> incomings(26, 0);
        for (int src = 0; src < 26; ++src) {
            for (int tgt : graph[src]) {
                incomings[tgt]++;
            }
        }

        vector<bool> has_nodes(26, false);
        for (const string& word : words) {
            for (char c : word) {
                has_nodes[c-'a'] = true;
            }
        }
        int node_count = 0;
        for (int node = 0; node < 26; ++node) {
            if (!has_nodes[node]) {
                continue;
            }
            node_count++;
            if (incomings[node] == 0) {
                que.push(node);
            }
        }

        string result;
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            result.push_back('a' + node);

            for (int next_node : graph[node]) {
                if (--incomings[next_node] == 0) {
                    que.push(next_node);
                }
            }
        }

        return node_count == (int)result.size() ? result : "";
    }
};

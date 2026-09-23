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
        return m <= n;
    }
public:
    string foreignDictionary(vector<string>& words) {
        // build graph: edge is the order
        int n = words.size();
        vector<bool> visited(26, false);
        vector<vector<int>> graph(26);
        for (const auto word : words) {
            for (char c : word) {
                visited[c-'a'] = true;
            }
        }

        for (int i = 1; i < n; ++i) {
            const string& word1 = words[i-1];
            const string& word2 = words[i];
            if (!build_graph(word1, word2, graph)) {
                return "";
            }
        }
        // use cycle detection to check
        vector<int> incomings(26, 0);
        for (int src = 0; src < 26; ++src) {
            for (int tgt : graph[src]) {
                incomings[tgt]++;
            }
        }
        
        // node
        queue<int> que;
        for (int i = 0; i < 26; ++i) {
            if (!visited[i]) {
                continue;
            }
            if (incomings[i] == 0) {
                que.push(i);
            }
        }

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (visited[i]) {
                ++count;
            }
        }
        string result;
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            result.push_back('a'+node);
            for (int tgt : graph[node]) {
                if (--incomings[tgt] == 0) {
                    que.push(tgt);
                }
            }
        }

        return (int)result.size() == count ? result : "";
    }
};


// h -> e -> r
// n -> f
// r -> n
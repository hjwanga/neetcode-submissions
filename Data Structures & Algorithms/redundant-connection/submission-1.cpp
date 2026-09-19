class Solution {
    class UnionFind {
        vector<int> root;
        vector<int> rank;
    public:
        UnionFind(int n) {
            root.resize(n);
            iota(root.begin(), root.end(), 0);
            rank.resize(n);
        }

        int find(int node) {
            if (root[node] == node) {
                return node;
            }
            return root[node] = find(root[node]);
        }

        void merge(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 == root2) {
                return;
            }
            if (rank[root1] < rank[root2]) {
                root[root1] = root2;
            } else if (rank[root2] < rank[root1]) {
                root[root2] = root1;
            } else {
                root[root2] = root1;
                rank[root1]++;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 1. get n
        int n = 0;
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            n = max({n, node1, node2});
        }

        // 2. merge edge
        // node is 1-based
        UnionFind uf(n+1);
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int root1 = uf.find(node1);
            int root2 = uf.find(node2);
            // has cycle
            if (root1 == root2) {
                return {node1, node2}; 
            }
            uf.merge(node1, node2);
        }
        return {};
    }
};



// node 1-based: 1-n
// 原本是Tree:  n個node, n-1個edge. fully connected
// 現在新增一個redundant edge, 找出他
// 現在有cycle

// <Idea> 
// 1.find out cycle
// 2.choose one edge on this cycle
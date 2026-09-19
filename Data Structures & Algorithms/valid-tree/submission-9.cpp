class Solution {
    class UnionFind {
        vector<int> root;
        vector<int> rank;
        int count;
    public:
        UnionFind(int n) {
            count = n;
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
            --count;
        }

        int island_count() {
            return count;
        }
    };
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        // constraint 1:
        if (n-1 != m) {
            return false;
        }

        // constraint 2:
        // island = 1
        UnionFind uf(n);
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            uf.merge(node1, node2);
        }
        return uf.island_count() == 1;
    }
};

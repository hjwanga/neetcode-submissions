class Solution {
    // <dist, u, v>
    using State = tuple<int,int,int>;
    int get_dist(const vector<int>& p1, const vector<int>& p2) {
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        return abs(x1-x2) + abs(y1-y2);
    }

    class UnionFind {
        vector<int> ranks;
        vector<int> roots;
        int count = 0;
    public:
        UnionFind(int n) {
            ranks.resize(n, 0);
            roots.resize(n, 0);
            iota(roots.begin(), roots.end(), 0);
            count = n;
        }

        int find(int node) {
            if (roots[node] == node) {
                return node;
            }
            return roots[node] = find(roots[node]);
        }

        void merge(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 == root2) {
                return;
            }
            if (ranks[root1] < ranks[root2]) {
                roots[root1] = root2;
            } else if (ranks[root2] < ranks[root1]) {
                roots[root2] = root1;
            } else {
                roots[root2] = root1;
                ranks[root1]++;
            }
            --count;
        }

        bool is_connected(int node1, int node2) {
            return find(node1) == find(node2);
        }

        int get_island() {
            return count;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Kruskal
        vector<State> dists;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int dist = get_dist(points[i], points[j]);
                dists.emplace_back(dist, i, j);
            }
        }
        // 1.sort
        sort(dists.begin(), dists.end());

        // 2.disjoint set
        int result = 0;
        UnionFind uf(n);
        for (const auto& [dist, u, v] : dists) {
            if (uf.is_connected(u, v)) {
                continue;
            }
            result += dist;
            uf.merge(u, v);
            if (uf.get_island() == 1) {
                break;
            }
        }
        return result;
    }
};

// minimum spanning tree
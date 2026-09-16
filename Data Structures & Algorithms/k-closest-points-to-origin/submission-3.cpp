class Solution {
    struct Point {
        Point() = default;
        Point(int x, int y): x(x), y(y){}
        int x = 0;
        int y = 0;
    };
    int get_dist(const Point& p) {
        return p.x*p.x + p.y*p.y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        result.reserve(k);
        auto cmp = [](const Point& lhs, const Point& rhs) {
            int l_dist = lhs.x*lhs.x+lhs.y*lhs.y;
            int r_dist = rhs.x*rhs.x+rhs.y*rhs.y;
            if (l_dist != r_dist) {
                return l_dist < r_dist;
            }
            return true;
        };
        priority_queue<Point, vector<Point>, decltype(cmp)> pq;
        for (const vector<int>& point : points) {
            Point p(point[0], point[1]);
            pq.push(p);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            result.push_back({p.x, p.y});
        }
        return result;
    }
};

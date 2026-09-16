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
        auto cmp = [this](const Point& lhs, const Point& rhs) {
            int l_dist = get_dist(lhs);
            int r_dist = get_dist(rhs);
            return l_dist < r_dist;
        };
        priority_queue<Point, vector<Point>, decltype(cmp)> pq(cmp);
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

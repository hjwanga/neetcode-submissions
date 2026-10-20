class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 1. sorting by end
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs){
            if (lhs[1] != rhs[1]) {
                return lhs[1] < rhs[1];
            }
            if (lhs[0] != rhs[0]) {
                return lhs[0] > rhs[0];
            }
            return false;
        };
        sort(intervals.begin(), intervals.end(), cmp);

        // 2. check overlap
        int n = intervals.size();
        int result = 0;
        int e1 = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            // 不重疊
            if (e1 <= s2) {
                e1 = e2;
            } else {
                // 重疊
                ++result;
            }
        }
        return result;
    }
};


//  1---2
//      2----4


// 1---2
//     2----4
// 1--------4
//           5------9
//     2-----------------10
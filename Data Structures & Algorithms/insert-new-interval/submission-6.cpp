class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        // 1. lower_bound of newInterval start
        int insert_pos = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();

        // 2.
        //  lhs     insert pos    rhs
        // [ ..... |          |  .... ]
        auto merge = [&result](const vector<int>& interval) {
            if (result.empty()) {
                result.push_back(interval);
                return;
            }
            int s2 = interval[0];
            int e2 = interval[1];
            if (result.back()[1] < s2) {
                result.push_back({s2, e2});
            } else {
                result.back()[1] = max(result.back()[1], e2);
            }
        };

        // lhs
        for (int i = 0; i < insert_pos; ++i) {
            merge(intervals[i]);
        }
        
        // insert pos
        merge(newInterval);

        // rhs
        for (int i = insert_pos; i < n; ++i) {
            merge(intervals[i]);
        }
        
        return result;
    }
};

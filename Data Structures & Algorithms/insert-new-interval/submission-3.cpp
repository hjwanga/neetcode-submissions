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

        // lhs
        for (int i = 0; i < insert_pos; ++i) {
            result.push_back(intervals[i]);
        }
        
        for (int i = insert_pos-1; i < n; ++i) {
            if (result.empty()) {
                result.push_back(newInterval);
                continue;
            }
            // insert, rhs
            int s2 = i == insert_pos-1 ? newInterval[0] : intervals[i][0];
            int e2 = i == insert_pos-1 ? newInterval[1] : intervals[i][1];
            if (result.back()[1] < s2) {
                result.push_back({s2, e2});
            } else {
                result.back()[1] = max(result.back()[1], e2);
            }
        }
        
        return result;
    }
};

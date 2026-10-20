class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 1. sort by begin
        sort(intervals.begin(), intervals.end());
        // 2. merge
        vector<vector<int>> result;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            // case1
            if (result.empty() || result.back()[1] < s2) {
                result.push_back({s2, e2});
            } else {
                // case2, case3
                result.back()[1] = max(result.back()[1], e2);
            }
        }
        return result;
    }
};

// case1 : 不重疊 新增
// s1---------e1
//                s2----------e2

// case2 : 重疊 延續
// s1---------e1
//     s2----------e2

// case3 : 重疊 不動
// s1---------e1
//     s2--e2


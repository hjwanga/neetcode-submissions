class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int n = intervals.size();
        result.reserve(n);
        int s1 = intervals[0][0];
        int e1 = intervals[0][1];
        result.push_back({s1, e1});
        for (int i = 1; i < n; ++i) {
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            // case1
            if (e1 < s2) {
                result.push_back({s2, e2});
                s1 = s2;
                e1 = e2;
                
            } else if (s2 <= e1) {
                result.back()[1] = max(e1, e2);
                e1 = result.back()[1];
            }
        }
        return result;
    }
};

// case1: 新增
//  s1---------e1
//                s2=====e2

// case2: 修改e1 -> e2
//  s1---------e1
//    s2===========e2


// case3: 不做事
//  s1---------e1
//    s2=====e2
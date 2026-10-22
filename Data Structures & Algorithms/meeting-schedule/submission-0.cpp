/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return true;
        }

        // 1. sort by end
        auto cmp = [](const Interval& lhs, const Interval& rhs){
            if (lhs.end != rhs.end) {
                return lhs.end < rhs.end;
            }
            if (lhs.start != rhs.start) {
                return lhs.start < rhs.start;
            }
            return false;
        };
        sort(intervals.begin(), intervals.end(), cmp);

        // 2. checking
        int e1 = intervals[0].end;
        for (int i = 1; i < n; ++i) {
            int s2 = intervals[i].start;
            int e2 = intervals[i].end;
            if (e1 <= s2) {
                e1 = e2;
            } else {
                return false;
            }
        }
        return true;
    }
};

//  5---10
//         15----20
// 0-------------------30

//   s1-----e1
//             s2----e2
//
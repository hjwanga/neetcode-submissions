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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return n;
        }
        int result = 1;
        // 1. sort by start
        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs){
            return lhs.start < rhs.start;
        });

        // 2. check, min heap
        int e1 = intervals[0].end;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(e1);
        for (int i = 1; i < n; ++i) {
            int s2 = intervals[i].start;
            int e2 = intervals[i].end;
            // 不重疊
            if (pq.top() <= s2) {
                pq.pop();
            } else {
                // 重疊. 需要新的房間
                ++result;
            }
            pq.push(e2);
        }
        return result;
    }
};

//  s1-------e1
//              s2-----e2
//  s1-------e1
//        s2-----e2


//   5--10
//         15--20
//           18--------30
// 0----------------------40



//    1---3
//      2----6
//          5----8          
//  0-------------10
//             7------12

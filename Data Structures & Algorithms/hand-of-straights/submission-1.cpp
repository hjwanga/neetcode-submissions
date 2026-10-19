class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());

        // counting
        map<int, int> counts;
        for (int num : hand) {
            counts[num]++;
        }

        for (auto [num, count] : counts) {
            if (count == 0) {
                continue;
            }
            int remains = count;
            for (int j = 0; j < groupSize; ++j) {
                if (!counts.count(num+j)) {
                    return false;
                }
                if (counts[num+j] - remains < 0) {
                    return false;
                }
                counts[num+j] -= remains;
            }
        }

        // for (int num = l_num; num <= r_num; ++num) {
        //     if (counts[num] == 0) {
        //         continue;
        //     }
        //     int remains = counts[num];
        //     for (int j = 0; j < groupSize; ++j) {
        //         if (counts[num+j] - remains < 0) {
        //             return false;
        //         }
        //         counts[num+j] -= remains;
        //     }
        // }
        return true;
    }
};



// hand = [1,2,4,2,3,5,3,4],  groupSize = 4
//         1 2 2 3 3 4 4 5

// hand = [1,2,3,3,4,5,6,7], groupSize = 4
//         1 2 3 3 4 5 6 7
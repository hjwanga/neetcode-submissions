class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());

        // counting
        int counts[1001]{};
        for (int num : hand) {
            counts[num]++;
        }

        int l_num = hand.front();
        int r_num = hand.back();
        for (int num = l_num; num <= r_num; ++num) {
            if (counts[num] == 0) {
                continue;
            }
            int remains = counts[num];
            for (int j = 0; j < groupSize; ++j) {
                if (counts[num+j] - remains < 0) {
                    return false;
                }
                counts[num+j] -= remains;
            }
        }
        return true;
    }
};



// hand = [1,2,4,2,3,5,3,4],  groupSize = 4
//         1 2 2 3 3 4 4 5

// hand = [1,2,3,3,4,5,6,7], groupSize = 4
//         1 2 3 3 4 5 6 7
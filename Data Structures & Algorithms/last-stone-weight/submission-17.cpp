class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max_num = *max_element(stones.begin(), stones.end());
        vector<int> counts(max_num+1, 0);
        for (int stone : stones) {
            counts[stone]++;
        }

        for (int i = max_num; i > 0;) {
            // 偶數互碰消除
            if (counts[i] % 2 == 0) {
                counts[i] = 0;
                --i;
                continue;
            }
            counts[i] = 1;
            
            int j = i-1;
            while (j > 0 && counts[j] == 0) {
                --j;
            }
            if (j <= 0) {
                return i;
            }
            int y = i;
            int x = j;
            counts[y]--;
            counts[x]--;
            counts[y-x]++;

            // 有可能碰撞完的石頭(y-x)比x大, 所以i要取兩者大的那個
            i = max(y-x, x);
        }
        return 0;
    }
};
// stones = [2,3,6,2,4]
//   0 1 2 3 4 5 6
//  [0 0 3 1 0 0 0]
//i          ^
//j          
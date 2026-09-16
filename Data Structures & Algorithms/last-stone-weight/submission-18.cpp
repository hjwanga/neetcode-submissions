class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max_num = *max_element(stones.begin(), stones.end());
        vector<int> counts(max_num+1, 0);

        for (int stone : stones) {
            counts[stone]++;
        }

        for (int i = max_num; i > 0;) {
            if (counts[i]%2 == 0) {
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
            i = max(y-x, x);
        }
        return 0;
    }
};

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool r1 = false;
        bool r2 = false;
        bool r3 = false;
        for (const auto& triplet : triplets) {
            int a = triplet[0];
            int b = triplet[1];
            int c = triplet[2];
            if (a > target[0] || b > target[1] || c > target[2]) {
                continue;
            }
            r1 |= a == target[0];
            r2 |= b == target[1];
            r3 |= c == target[2];
        }
        return r1 && r2 && r3;
    }
};

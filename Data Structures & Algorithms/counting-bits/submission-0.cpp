class Solution {
    int count1(int num) {
        int result = 0;
        while (num) {
            ++result;
            num = num&(num-1);
        }
        return result;
    }
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.reserve(n+1);
        for (int num = 0; num <= n; ++num) {
            result.push_back(count1(num));
        }
        return result;
    }
};

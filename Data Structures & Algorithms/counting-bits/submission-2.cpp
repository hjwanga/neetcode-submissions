class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        if (n == 1) {
            return {0, 1};
        }
        vector<int> result;
        result.reserve(n+1);
        // init condition
        result.push_back(0);
        result.push_back(1);
        for (int num = 2; num <= n; ++num) {
            int least_sig_bit = num&(-num);
            int one_sol = result[num-least_sig_bit]+1;
            result.push_back(one_sol);
        }
        return result;
    }
};

// DP[i] := number為i的情況下, countBits是多少?
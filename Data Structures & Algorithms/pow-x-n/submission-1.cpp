class Solution {
public:
    double myPow(double x, int n) {
        // 將 n 拆成二進位表示
        // factor: x^1 x^2 x^4 x^8
        long long N = n;
        if (N < 0) {
            x = 1.0/x;
            N = -N;
        }
        double result = 1.0;
        while (N > 0) {
            if (N&1LL) {
                result = result * x;
            }
            x = x*x;
            N = N >> 1LL;
        }
        return result;
    }
};

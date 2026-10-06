class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        unsigned int mask = 1;
        unsigned int result = 0;
        while (mask != 0) {
            int x = a&1;
            int y = b&1;
            int sum = carry ^ x ^ y;
            carry = (carry & y) | (carry & x) | (x & y);
            if (sum) {
                result = result | mask;
            }
            a = a >> 1;
            b = b >> 1;
            mask = mask << 1U;
        }
        return result;
    }
};

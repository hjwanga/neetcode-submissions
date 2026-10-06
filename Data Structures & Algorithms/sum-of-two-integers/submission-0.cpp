class Solution {
    int add(int a, int b) {
        int result = 0;
        int carry = 0;
        for (int i = 0; i < 32; ++i) {
            int a_bit = a&1;
            int b_bit = b&1;
            int final_bit = 0;
            if (carry == 1) {
                if (a_bit == 1 && b_bit == 1) {
                    final_bit = 1;
                    carry = 1;
                } else if (a_bit == 0 && b_bit == 0) {
                    final_bit = 1;
                    carry = 0;
                } else {
                    final_bit = 0;
                    carry = 1;
                }
            } else {
                if (a_bit == 1 && b_bit == 1) {
                    final_bit = 0;
                    carry = 1;
                } else if (a_bit == 0 && b_bit == 0) {
                    final_bit = 0;
                    carry = 0;
                } else {
                    final_bit = 1;
                    carry = 0;
                }
            }
            result |= (final_bit << i);
            a >>= 1;
            b >>= 1;
        }
        return result;
    }
public:
    int getSum(int a, int b) {
        return add(a, b);
    }
};


// -1: 1 1111
//  1: 0 0001
//  0: 0 0000

// -1: 1 1111
// -1: 1 1111
// -2: 1 1110
//     1 1110
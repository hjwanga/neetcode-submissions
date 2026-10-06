class Solution {
public:
    int reverse(int x) {
        bool is_negative = x < 0;
        unsigned int new_x = is_negative ? -x : x;
        int result = 0;
        while (new_x) {
            int num = new_x%10U;
            if (is_negative) {
                if (result < -214748364 || result == -214748364 && num > 8) {
                    return 0;
                }
                result = result*10 - num;
            } else {
                if (result > 214748364 || result == 214748364 && num > 7) {
                    return 0;
                }
                result = result*10 + num;
            }
            new_x = new_x/10U;
        }
        return result;
    }
};


// new_x = 1234
// stk: 4 3 2 1

// -2,147,483,648 到 2,147,483,647（即 -2³¹ 至 2³¹ - 1）
// -214,748,364 
//  214,748,364
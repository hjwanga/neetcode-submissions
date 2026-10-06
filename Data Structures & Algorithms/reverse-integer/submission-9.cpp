class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            int digit = x%10;
            if (result > INT_MAX/10 || (result == INT_MAX/10 && digit > INT_MAX%10)) {
                return 0;
            }
            if (result < INT_MIN/10 || (result == INT_MIN/10 && digit < INT_MIN%10)) {
                return 0;
            }
            result = result*10 + digit;
            x = x/10;
        }
        return result;
    }
};


// new_x = 1234
// stk: 4 3 2 1

// -2,147,483,648 到 2,147,483,647（即 -2³¹ 至 2³¹ - 1）
// -214,748,364 
//  214,748,364
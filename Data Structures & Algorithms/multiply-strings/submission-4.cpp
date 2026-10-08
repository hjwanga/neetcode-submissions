class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        if (m == 1 && num1[0] == '0' || n == 1 && num2[0] == '0') {
            return "0";
        }

        string result(m+n, '0');
        for (int i = 0; i < n; ++i) {
            int digit_2 = num2[n-1-i]-'0';
            for (int j = 0; j < m; ++j) {
                int carry = 0;
                int digit_1 = num1[m-1-j]-'0';
                int digit_final = digit_2*digit_1 + carry + (result[i+j]-'0');
                carry = digit_final/10;
                digit_final = digit_final%10;
                result[i+j] = digit_final + '0';
                if (carry) {
                    result[i+j+1] = (result[i+j+1]+carry);
                }
            }
        }
        if (result[m+n-1] == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//  num1:  999 m = 3
//  num2:    9 n = 1
//  -----------
//        8991
// carry = 8
// digit_final = 9

//result [0 1 2 3]
//        1 9 9 8

//  num1:  999 m = 3
//  num2:   99 n = 2
//  -----------
//        8991
//       98901
// carry = 9
// digit_final = 8

//result [0 1 2 3 4]
//        1 0 9 8 9
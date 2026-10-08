class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        result.reserve(digits.size()+1);
        int n = digits.size();
        int carry = 1; // plus 1
        for (int i = n-1; i >= 0; --i) {
            int digit = digits[i] + carry;
            if (digit >= 10) {
                digit -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result.push_back(digit);
        }
        if (carry) {
            result.push_back(carry);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

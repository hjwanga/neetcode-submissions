class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int lo = 0;
        int hi = 0;
        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else {
                lo--;
                hi++;
            }
            if (hi < 0) {
                return false;
            }
            lo = max(0, lo);
        }
        return lo == 0;
    }
};


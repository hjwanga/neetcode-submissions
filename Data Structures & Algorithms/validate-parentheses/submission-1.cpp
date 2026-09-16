class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push_back(c);
            }
            else {
                if (stk.empty()) {
                    return false;
                }
                char left = stk.back();
                if (left == '(' && c == ')' || left == '[' && c == ']' || left == '{' && c == '}') {
                    stk.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

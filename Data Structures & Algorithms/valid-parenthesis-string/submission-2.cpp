class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        int n = s.size();
        // 1.塞入left/star
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') {
                left.push(i);
            } else if (c == '*') {
                star.push(i);
            } else {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }
        
        // 2.處理剩餘的left
        while (!left.empty() && !star.empty()) {
            int left_index = left.top();
            left.pop();
            int star_index = star.top();
            star.pop();
            if (left_index > star_index) {
                return false;
            }
        }
        return left.empty();
    }
};

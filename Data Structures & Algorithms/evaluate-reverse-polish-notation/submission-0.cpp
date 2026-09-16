class Solution {
    bool is_op(const string& str) {
        return str.size() == 1 && !isdigit(str[0]);
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const auto& token : tokens) {
            if (is_op(token)) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                char c = token[0];
                int new_val = 0;
                switch (c) {
                    case '+':
                        new_val = a+b;
                    break;
                    case '-':
                        new_val = a-b;
                    break;
                    case '*':
                        new_val = a*b;
                    break;
                    case '/':
                        new_val = a/b;
                    break;
                    default:
                    break;
                }
                stk.push(new_val);
            }
            else {
                stk.push(atoi(token.data()));
            }
        }
        return stk.top();
    }
};

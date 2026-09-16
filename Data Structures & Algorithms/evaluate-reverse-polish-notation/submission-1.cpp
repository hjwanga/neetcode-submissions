class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int,int)>> OP;
        OP["+"] = [](int a, int b) {return a+b;};
        OP["-"] = [](int a, int b) {return a-b;};
        OP["*"] = [](int a, int b) {return a*b;};
        OP["/"] = [](int a, int b) {return a/b;};
        stack<int> stk;
        for (const auto& token : tokens) {
            if (!OP.count(token)) {
                stk.push(stoi(token));
            }
            else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int new_num = OP[token](a, b);
                stk.push(new_num);
            }
        }
        return stk.top();
    }
};

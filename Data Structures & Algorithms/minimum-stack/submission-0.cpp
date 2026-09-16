class MinStack {
    using pii = pair<int,int>;
    // <value, min value of stack>
    vector<pii> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.emplace_back(val, val);
            return;
        }
        auto [_, min_val] = stk.back();
        if (val <= min_val) {
            stk.emplace_back(val, val);
        }
        else {
            stk.emplace_back(val, min_val);
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

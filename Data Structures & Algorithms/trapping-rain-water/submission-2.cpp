class Solution {
public:
    int trap(vector<int>& height) {
        // CORE: left walls are in stack
        int n = height.size();
        int result = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int l = stk.top();
                    int h = min(height[l], height[i]) - height[mid];
                    int w = i - l - 1;
                    h = h > 0 ? h : 0;
                    result += h*w;
                }
            }
            stk.push(i);
        }
        return result;
    }
};


//  0 1 2 3 4 5
// [5 4 3 3 3 7]

// stack: 0, 1, 2

// (h[stack.top()])* (i-stack.top()-1)
//      0 1 2 3 4 5
// height=[4,2,0,3,2,5]

// stack: 0
// mid: 1
// l = 1

// 3


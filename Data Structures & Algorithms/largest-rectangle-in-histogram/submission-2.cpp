class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // [index, height]
        using pii = pair<int, int>;
        stack<pii> stk;
        int n = heights.size();
        int result = 0;
        // monotonic increasing
        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            int last_i = i;
            while (!stk.empty()) {
                auto [top_index, top_h] = stk.top();
                if (top_h > h) {
                    result = max(result, (i-top_index)*top_h);
                    last_i = top_index;
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.emplace(last_i, h);
        }

        // no right bound anymore
        while (!stk.empty()) {
            auto [top_index, top_h] = stk.top();
            stk.pop();
            result = max(result, static_cast<int>(heights.size() - top_index)*top_h);
        }
        return result;
    }
};

// 0 1 2 3 4 5 
// 7 1 7 2 2 4
// last_index = 2
// stk: [1,1] [2,2] [5,4]

// max: 7
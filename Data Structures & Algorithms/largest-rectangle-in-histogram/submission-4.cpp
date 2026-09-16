class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // <index, height>
        using pii = pair<int,int>;
        // monotonic increasing: guarantee left bar bound (no way to extend left)
        stack<pii> stk;
        int n = heights.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int start_i = i;
            int h = heights[i];
            // it means right bar bound
            while (!stk.empty() && stk.top().second > h) {
                auto [top_index, top_h] = stk.top();
                stk.pop();
                result = max(result, (i-top_index)*top_h);
                start_i = top_index;
            }
            stk.emplace(start_i, h);
        }
        // deal with the remaining part
        while (!stk.empty()) {
            auto [top_index, top_h] = stk.top();
            stk.pop();
            result = max(result, (n-top_index)*top_h);
        }

        return result;
    }
};

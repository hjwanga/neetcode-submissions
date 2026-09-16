class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic stack: decreasing
        // <index, value>
        using pii = pair<int,int>;
        stack<pii> stk;

        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            int temp = temperatures[i];
            while (!stk.empty() && stk.top().second < temp) {
                auto [j, t] = stk.top();
                stk.pop();
                result[j] = i-j;
            }
            stk.emplace(i, temp);
        }
        return result;
    }
};

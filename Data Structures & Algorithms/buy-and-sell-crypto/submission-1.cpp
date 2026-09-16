class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int result = 0;
        for (int i = 1; i < n; ++i) {
            int sell = prices[i];
            result = max(result, sell-buy);
            if (sell < buy) {
                buy = sell;
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // logic: keep a lowest buy
        int low_buy = prices[0];
        int n = prices.size();
        int result = 0;
        for (int i = 1; i < n; ++i) {
            int sell = prices[i];
            if (sell < low_buy) {
                low_buy = sell;
            }
            else {
                result = max(result, sell-low_buy);
            }
        }
        return result;
    }
};


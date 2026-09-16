class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force
        int n = prices.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int buy = prices[i];
            for (int j = i+1; j < n; ++j) {
                int sell = prices[j];
                result = max(result, sell-buy);
            }
        }
        return result;
    }
};


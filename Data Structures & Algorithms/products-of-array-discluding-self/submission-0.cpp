class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        // Brute force O(n^2)
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int product = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                product *= nums[j];
            }
            result.push_back(product);
        }
        return result;
    }
};

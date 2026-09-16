class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        // given i, found valid l,r
        int n = nums.size();
        for (int i = 0; i < n-2; ++i) {
            // avoid duplicate given i
            if (i >= 1 && nums[i-1] == nums[i]) {
                continue;
            }
            int l = i+1;
            int r = n-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    --r;
                }
                else if (sum < 0) {
                    ++l;
                }
                else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    --r;
                    while (l < r && nums[r] == nums[r+1]) {
                        --r;
                    }
                }
            }
        }
        return result;
    }
};


// [-2, 0, 0, 2, 2]
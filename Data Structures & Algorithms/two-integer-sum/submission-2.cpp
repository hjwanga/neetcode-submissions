class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash for candidates of nums[j]. value, index
        unordered_map<int, int> h;
        // loop1: nums[i]
        // loop2: given nums[i], target. Find out nums[j]
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int numi = nums[i];
            int numj = target - numi;
            if (h.count(numj)) {
                return {h[numj], i};
            }
            h[numi] = i;
        }
        return {-1, -1};
    }
    //     int n = nums.size();
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = i+1; j < n; ++j) {
    //             if (nums[i] + nums[j] == target) {
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {-1, -1};
    // }
};


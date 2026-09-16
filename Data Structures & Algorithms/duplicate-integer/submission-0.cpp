class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            if (++counts[num] > 1) {
                return true;
            }
        }
        return false;
    }
};
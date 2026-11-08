class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        result.insert(result.end(), nums.begin(), nums.end());
        result.insert(result.end(), nums.begin(), nums.end());
        return result;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // <count, num>
        using pr = pair<int,int>;
        vector<pr> pairs;
        // <num, count>
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        for (auto& [num, count] : counts) {
            pairs.emplace_back(count, num);
        }
        sort(pairs.rbegin(), pairs.rend());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pairs[i].second);
        }
        return result;
    }
};


// 1:6
// 2:3
// 3:4

// <6,1> <4,3> <3,2>
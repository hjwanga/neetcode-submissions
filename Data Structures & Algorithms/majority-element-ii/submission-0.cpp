class Solution {
    using pii = pair<int,int>;
public:
    vector<int> majorityElement(vector<int>& nums) {
        // <num, counting>
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // keep 1st, 2nd pair <num, counting>
        pii first = make_pair(-1,-1);
        pii second = make_pair(-1,-1);
        for (const auto& [num, counting] : counts) {
            if (counting >= first.second) {
                swap(first, second);
                first = make_pair(num, counting);
            } else if (counting >= second.second) {
                second = make_pair(num, counting);
            }
        }

        // final check
        int n = nums.size();
        vector<int> result;
        if (first.second != -1 && first.second > n/3) {
            result.push_back(first.first);
        }
        if (second.second != -1 && second.second > n/3) {
            result.push_back(second.first);
        }
        return result;
    }
};
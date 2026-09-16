class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. sorting: 用freq 排序
        // TC: N*log(N)
        // SC: O(N)
        // // <count, num>
        // using pr = pair<int,int>;
        // vector<pr> pairs;
        // // <num, count>
        // unordered_map<int, int> counts;
        // for (int num : nums) {
        //     counts[num]++;
        // }
        // for (auto& [num, count] : counts) {
        //     pairs.emplace_back(count, num);
        // }
        // sort(pairs.rbegin(), pairs.rend());

        // vector<int> result;
        // for (int i = 0; i < k; ++i) {
        //     result.push_back(pairs[i].second);
        // }
        // return result;

        // 2. min heap: 超過k個就pop
        // TC: N*log(k)
        // SC: O(N)
        // <count, num>
        // using pr = pair<int,int>;
        // vector<pr> pairs;
        // // <num, count>
        // unordered_map<int, int> counts;
        // for (int num : nums) {
        //     counts[num]++;
        // }

        // priority_queue<pr, vector<pr>, greater<pr>> pq;
        // for (auto& [num, count] : counts) {
        //     pq.emplace(count, num);
        //     if (pq.size() > k) {
        //         pq.pop();
        //     }
        // }

        // vector<int> result;
        // for (int i = 0; i < k; ++i) {
        //     auto [count, num] = pq.top();
        //     pq.pop();
        //     result.push_back(num);
        // }
        // return result;

        // 3. bucket sort: freq當桶子, 相同freq的num放一起
        // TC: O(N)
        // SC: O(N)
        using pr = pair<int,int>;
        vector<pr> pairs;
        // <num, count>
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n+1, vector<int>());
        for (auto& [num, count] : counts) {
            buckets[count].push_back(num);
        }

        vector<int> result;
        for (auto it = buckets.rbegin(); it != buckets.rend() && k > 0; ++it) {
            auto& bucket = *it;
            for (int num : bucket) {
                result.push_back(num);
                --k;
                if (k == 0) {
                    break;
                }
            }
        }
        return result;
    }
};


// 1:6
// 2:3
// 3:4

// <6,1> <4,3> <3,2>
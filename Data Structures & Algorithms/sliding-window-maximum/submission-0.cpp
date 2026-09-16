class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> que;
        vector<int> result;
        // 1st pass
        for (int i = 0; i < k; ++i) {
            while (!que.empty() && que.back() < nums[i]) {
                que.pop_back();
            }
            que.push_back(nums[i]);
        }
        result.push_back(que.front());
        
        // 2nd pass
        for (int i = k; i < n; ++i) {
            int j = i-k;
            // remove old max
            if (!que.empty() && que.front() == nums[j]) {
                que.pop_front();
            }
            while (!que.empty() && que.back() < nums[i]) {
                que.pop_back();
            }
            que.push_back(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

// que: [4 2]
// result: [2 2 4]
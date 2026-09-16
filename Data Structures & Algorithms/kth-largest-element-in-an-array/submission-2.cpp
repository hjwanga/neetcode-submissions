class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sol1: use min heap
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (int num : nums) {
        //     pq.push(num);
        //     if ((int)pq.size() > k) {
        //         pq.pop();
        //     }
        // }
        // return pq.top();

        nth_element(nums.begin(), nums.begin() + k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};

// 1 2 3 4 5

// 1 1 2 3 4 5 5
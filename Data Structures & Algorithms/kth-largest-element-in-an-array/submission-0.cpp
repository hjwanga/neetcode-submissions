class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// 1 2 3 4 5

// 1 1 2 3 4 5 5
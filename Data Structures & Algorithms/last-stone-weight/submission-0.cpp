class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for (int stone : stones) {
            pq.push(stone);
        }
        while (pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            // case1
            if (x == y) {
                continue;
            } else {
            // case2
                pq.push(abs(x-y));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

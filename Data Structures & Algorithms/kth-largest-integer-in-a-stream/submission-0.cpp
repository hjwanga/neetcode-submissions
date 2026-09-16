class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for (int num : nums) {
            pq.push(num);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if ((int)pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};


// k = 3
// 1 2 3 3
//   ^
// add 3
// 1 2 3 3 3
//     ^
// add 5
// 1 2 3 3 3 5
//       ^    
// add 6
// 1 2 3 3 3 5 6
//         ^
// add 7
// 1 2 3 3 3 5 6 7
//           ^
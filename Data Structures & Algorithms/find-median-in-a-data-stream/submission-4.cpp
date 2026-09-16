class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min_h;
    priority_queue<int, vector<int>, less<int>> max_h;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_h.push(num);
        // condition1: balance
        if ((int)max_h.size() - (int)min_h.size() >= 2) {
            int val = max_h.top();
            max_h.pop();
            min_h.push(val);
        }
        // condition2: max_h.top() <= min_h.top()
        if (!max_h.empty() && !min_h.empty() && max_h.top() > min_h.top()) {
            int max_top = max_h.top();
            int min_top = min_h.top();
            max_h.pop();
            min_h.pop();
            max_h.push(min_top);
            min_h.push(max_top);
        }
    }
    
    double findMedian() {
        int m = min_h.size();
        int n = max_h.size();
        bool odd = (m+n)%2;
        if (odd) {
            return max_h.top();
        }
        return (min_h.top() + max_h.top())/2.0;
    }
};

// 1 3 2
// max_h : 1 
// min_h : 3

// 1 2 3 4 -> (2+3)/2
// 1 2 3 -> 2

// 0 ... (mid-1| mid) .... n-1
//             |

// max_heap | min_heap
// condition:
// 1. (max_heap.size() - min_heap.size()) <= 1
// 2. max_heap.top() <= min_heap.top()
class MyCircularQueue {
    int len = 0;
    int k = 0;
    int l = 0;
    int r = 0;
    vector<int> nums;
public:
    MyCircularQueue(int k):k(k) {
        nums.resize(k, 0);
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        nums[r] = value;
        r = (r+1)%k;
        ++len;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        l = (l+1)%k;
        --len;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return nums[l];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return nums[(r+k-1)%k];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // fast meets slow
            if (slow == fast) {
                break;
            }
        }
        // move slow to original and both's speed = 1 move
        slow = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast) {
                break;
            }
        }
        return slow;
    }
};


// pigeon hole theorem
//  0 1 2 3 4
// [1,2,3,4,2]

// 0->1
// 1->2
// 2->3
// 3->4
// 4->2


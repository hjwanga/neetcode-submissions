class Solution {
    int move_one_step(int num) {
        int result = 0;
        while (num) {
            int digit = num%10;
            result += digit*digit;
            num = num/10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        // cycle detection
        int slow = n;
        int fast = n;
        while (true) {
            slow = move_one_step(slow);
            fast = move_one_step(move_one_step(fast));
            if (slow == fast) {
                break;
            }
        }
        return slow == 1;
    }
};


// 101 -> 1 + 0 + 1 = 2
// 2 -> 4
// 4 -> 16
// 16 -> 1 + 36 = 37
// 37 -> 9 + 49 = 58
// 58 -> 25 + 64 = 89
// 89 -> 64 + 81 = 145 
// 145 -> 1 + 16 + 25 = 42
// 42 -> 16 + 4 = 20
// 20 -> 4

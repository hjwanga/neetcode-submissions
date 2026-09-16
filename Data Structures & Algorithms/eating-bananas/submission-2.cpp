class Solution {
    bool is_eaten_all(const vector<int>& piles, int h, int speed) {
        for (int pile : piles) {
            int q = pile/speed;
            int r = pile%speed;
            if (r > 0) {
                ++q;
            }
            h -= q;
        
            if (h < 0) {
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // step1: l = 1, r = 1e9;
        // XXXX|OOOOO
        //      ^
        // 1234|5678
        //      ^
        int l = 1;
        int r = 1e9;
        while (l <= r) {
            int mid = l + (r-l)/2;
            bool eaten_all = is_eaten_all(piles, h, mid);
            if (eaten_all) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};

// l = 1, r = 8
// mid = 4
// l = 4+1=5, r = 8
// mid = 6
// l = 5, r = 6-1=5
// mid = 5
// l = 5, r = 5-1=4


// l = 1, r = 7
// mid = 4
// l = 4+1=5, r = 7
// mid = 6
// l = 5, r = 6-1=5
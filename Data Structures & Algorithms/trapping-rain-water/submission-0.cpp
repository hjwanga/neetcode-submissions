class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // rhs[i] := the max height from i+1 i+2 ..0 n-1 
        // lhs[i] := the max height from i-1 i-2 ... 0
        vector<int> rhs(n, 0);
        vector<int> lhs(n, 0);

        for (int i = n-2; i >= 0; --i) {
            rhs[i] = max(rhs[i+1], height[i+1]);
        }
        for (int i = 1; i < n; ++i) {
            lhs[i] = max(lhs[i-1], height[i-1]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = min(lhs[i], rhs[i]) - height[i];
            result += tmp > 0 ? tmp : 0;
        }
        return result;
    }
};


// result += min(lhs[i], rhs[i]) - height[i]

// height = [0,2,0,3,1,0,1,3,2,1]
// rhs =     3 3 3 3 3 3 3 2 1 0
// lhs =     0 0 2 2 3 3 3 3 3 3
// ----------------------------------
//           0 0 2 0 2 3 2 0 0 0
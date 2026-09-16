class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // // Brute force O(n^2)
        // vector<int> result;
        // int n = nums.size();
        // for (int i = 0; i < n; ++i) {
        //     int product = 1;
        //     for (int j = 0; j < n; ++j) {
        //         if (i == j) {
        //             continue;
        //         }
        //         product *= nums[j];
        //     }
        //     result.push_back(product);
        // }
        // return result;
        
        // Prefix product
        vector<int> result;
        int n = nums.size();
        vector<int> plr(n, 0);
        for (int i = 0; i < n; ++i) {
            plr[i] = (i == 0) ? nums[i] : plr[i-1]*nums[i];
        }
        vector<int> prl(n, 0);
        for (int i = n-1; i >= 0; --i) {
            prl[i] = (i == n-1) ? nums[i] : prl[i+1]*nums[i];
        }

        for (int i = 0; i < n; ++i) {
            int num = 0;
            int num_plr = (i-1 < 0) ? 1 : plr[i-1];
            int num_prl = (i+1 >= n) ? 1 : prl[i+1];
            num = num_plr * num_prl;
            result.push_back(num);
        }
        return result;
    }
};

// a1 a2 a3 a4

// -> a2a3a4, a1a3a4, a1a2a4, a1a2a3

//       a1,   a1a2, a1a2a3, a1a2a3a4

// a1a2a3a4, a2a3a4,   a3a4,       a4

// 1.prefix product left -> right : plr
// 2.prefix product left <- right : prl
// 3.product of i  = plr[i-1] * prl[i+1]
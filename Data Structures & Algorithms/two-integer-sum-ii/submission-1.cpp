class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n-1; ++i) {
            int new_tg = target - numbers[i];
            int l = i+1;
            int r = n-1;
            while (l <= r) {
                int mid = l + (r-l)/2;
                int num = numbers[mid];
                if (num == new_tg) {
                    return {i+1, mid+1};
                } else if (num > new_tg) {
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
// [2,1,1,3,1,4,5,6]
//            ^
//  <num, count>
//.  1     0
//.  1     0

        int num1 = 0;
        int num2 = 0;
        int count1 = 0;
        int count2 = 0;
        // two candidates
        // NOTE:判斷順序:一定要先檢查「是否等於現有候選人」,再檢查「有沒有空位」。
        // 例子: [2,1,1,3,1,4,5,6]
        for (int num : nums) {
            // 是否等於現有候選人
            if (count1 > 0 &&num1 == num) {
                ++count1;
            // 是否等於現有候選人
            } else if (count2 > 0 &&num2 == num) {
                ++count2;
            // 有沒有空位
            } else if (count1 == 0) {
                count1 = 1;
                num1 = num;
            // 有沒有空位
            } else if (count2 == 0) {
                count2 = 1;
                num2 = num;
            } else {
                --count1;
                --count2;
            }
        }
        // final check
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == num1) {
                ++count1;
            } else if (num == num2) {
                ++count2;
            }
        }
        vector<int> result;
        int n = nums.size();
        if (count1 > n/3) {
            result.push_back(num1);
        }
        if (count2 > n/3) {
            result.push_back(num2);
        }
        return result;
    }
};
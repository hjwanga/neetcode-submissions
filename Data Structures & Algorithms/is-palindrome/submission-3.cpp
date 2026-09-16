class Solution {
public:
    bool isPalindrome(string s) {
        // // 字串反轉, 比較
        // string result;
        // for (char c : s) {
        //     if (!isalnum(c)) {
        //         continue;
        //     }
        //     result.push_back(tolower(c));
        // }
        // return result == string(result.rbegin(), result.rend());

        // 雙指標
        int n = s.size();
        int l = 0;
        int r = n-1;
        while (l <= r) {
            while (l < n && !isalnum(s[l])) {
                ++l;
            }
            while (r >= 0 && !isalnum(s[r])) {
                --r;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};

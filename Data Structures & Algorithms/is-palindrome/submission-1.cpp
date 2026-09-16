class Solution {
    bool is_valid(char c) {
        bool rule2 = 'a' <= c && c <= 'z';
        bool rule3 = '0' <= c && c <= '9';
        return rule2 || rule3;
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (char& c : s) {
            if ('A' <= c && c <= 'Z') {
                c = 'a' + (c-'A');
            }
        }
        int i = 0;
        int j = n-1;
        while (i <= j) {
            while(i < n && !is_valid(s[i])) {
                ++i;
            }
            while(j >= 0 && !is_valid(s[j])) {
                --j;
            }
            if (i > j) {
                break;
            }

            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

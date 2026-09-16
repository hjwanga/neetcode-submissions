class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for (char c : s) {
            if (!isalnum(c)) {
                continue;
            }
            result.push_back(tolower(c));
        }
        return result == string(result.rbegin(), result.rend());
    }
};

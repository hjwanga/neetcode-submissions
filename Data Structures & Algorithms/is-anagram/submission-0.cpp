class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counts;
        // step1: count s characters
        for (char c : s) {
            ++counts[c];
        }
        // step2: decrease t characters
        // early return : if counts < 0
        for (char c : t) {
            if (--counts[c] < 0) {
                return false;
            }
        }
        // step3: final pass, check whether counts > 0. if yes? return false
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (it->second > 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
    string get_key(const string& str) {
        int freqs[26]{};
        for (char c : str) {
            ++freqs[c-'a'];
        }
        string result;
        for (int i = 0; i < 26; ++i) {
            string tmp = to_string(i+'a') + to_string(freqs[i]);
            result += tmp;
        }
        return result;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cache;
        
        for (const auto& str : strs) {
            string key = get_key(str);
            cache[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& [_, group] : cache) {
            result.push_back(group);
        }
        return result;
    }
};


// unordered_map<int, vector<string>>
// key := int

// key = counts of all char of string
// formula := count of a * 0 + count of b * 100 + count of c * 200 ...

class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (const auto& str : strs) {
            int n = str.size();
            result += to_string(n) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        cout << s <<endl;
        vector<string> result;
        int n = s.size();
        for (int i = 0; i < n;) {
            // get len
            int len = 0;
            while (i < n && s[i] != '#') {
                len = len*10 + (s[i]-'0');
                ++i;
            }
            if (i >= n) {
                break;
            }
            // ignore '#'
            ++i;
            // read len of string
            result.push_back(s.substr(i, len));
            i += len;
        }
        return result;
    }
};

// <len of string> + # + string 

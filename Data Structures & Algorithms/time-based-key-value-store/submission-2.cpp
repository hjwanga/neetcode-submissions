class TimeMap {
    unordered_map<string, vector<pair<int, string>>> times;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        times[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!times.count(key)) {
            return "";
        }
        const auto& time = times[key];
        // upper_bound
        int n = time.size();
        int l = 0;
        int r = n-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (time[mid].first <= timestamp) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return l-1 < 0 ? "" : time[l-1].second;
    }
};

// str, str
// <key, value>

// upper_bound
// [alice] -> (1, happy) (3, sad)
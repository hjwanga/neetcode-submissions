class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. counting
        int counts[26]{};
        for (char task : tasks) {
            counts[task-'A']++;
        }

        // 2. cooling down queue 
        // <time, count>
        queue<pair<int, int>> cd;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 0) {
                continue;
            }
            cd.emplace(0, counts[i]);
        }

        // 3. ready priority_queue
        // <count>
        // if time >= cd.front().first ? push to ready
        // large count first
        priority_queue<int, vector<int>, less<int>> ready;
        int time = 0;
        while (!cd.empty() || !ready.empty()) {
            // idle: jump to next time
            if (ready.empty()) {
                time = max(time, cd.front().first); 
            }
            while (!cd.empty() && time >= cd.front().first) {
                ready.push(cd.front().second);
                cd.pop();
            }
            int count = ready.top();
            ready.pop();
            ++time;
            if (--count > 0) {
                cd.emplace(time + n, count);
            }
        }
        return time;
    }
};

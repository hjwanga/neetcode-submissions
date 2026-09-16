class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. record counts
        int counts[26]{};
        for (char task : tasks) {
            counts[task-'A']++;
        }
        // 2. push into cooling
        // <time, count>
        queue<pair<int,int>> cooling;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 0) {
                continue;
            }
            cooling.emplace(0, counts[i]);
        }

        // 3. push to ready if time >= cooling time
        // large count first
        int time = 0;
        priority_queue<int, vector<int>, less<int>> ready;
        while (!ready.empty() || !cooling.empty()) {
            if (ready.empty()) {
                time = max(time, cooling.front().first);
            }
                while (!cooling.empty() && time >= cooling.front().first) {
                    ready.push(cooling.front().second);
                    cooling.pop();
                }
            int count = ready.top();
            ready.pop();
            ++time;
            if (--count > 0) {
                cooling.emplace(time+n, count);
            }
        }
        return time;
    }
};

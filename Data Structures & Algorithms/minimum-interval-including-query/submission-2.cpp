class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // 1. sort by start
        sort(intervals.begin(), intervals.end());

        // 2. sort query
        int n = queries.size();
        vector<int> q_indice(n, 0);
        for (int i = 0; i < n; ++i) {
            q_indice[i] = i;
        }
        sort(q_indice.begin(), q_indice.end(), [&queries](int lhs, int rhs){
            return queries[lhs] < queries[rhs];
        });
        // q_indice= [0 1 2 3 4 5]
        // queries = [2,3,1,7,6,8]
        // -> sorting
        // q_indice= [2,0,1,4,3,5]
        // queries = [1,2,3,6,7,8]

        // 3. min heap.
        // <len, end time>
        using pii = pair<int,int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> result(n, -1);
        int m = intervals.size();
        int i = 0;
        for (int q_index : q_indice) {
            int q = queries[q_index];
            // 處理 start <= q
            while (i < m && intervals[i][0] <= q) {
                pq.emplace(intervals[i][1]-intervals[i][0]+1, intervals[i][1]);
                ++i;
            }

            // 排除掉 end < q的人
            while (!pq.empty() && q > pq.top().second) {
                pq.pop();
            }
            if (!pq.empty()) {
                result[q_index] = pq.top().first;
            }
        }
        return result;


        // vector<int> result;
        // for (int query : queries) {
        //     int min_len = INT_MAX;
        //     for (const auto& interval : intervals) {
        //         int s = interval[0];
        //         int e = interval[1];
        //         if (s <= query && query <= e) {
        //             min_len = min(min_len, e-s+1);
        //         }
        //     }
        //     if (min_len == INT_MAX) {
        //         min_len = -1;
        //     }
        //     result.push_back(min_len);
        // }
        // return result;
    }
};


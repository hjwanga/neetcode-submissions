class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int prefix_sum = 0;
        int index_lowest_prefix_sum = -1;
        int lowest_prefix_sum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = gas[i];
            int c = cost[i];
            prefix_sum += g-c;
            if (prefix_sum < lowest_prefix_sum) {
                lowest_prefix_sum = prefix_sum;
                index_lowest_prefix_sum = i;
            }
        }

        if (prefix_sum < 0) {
            return -1;
        }
        return (index_lowest_prefix_sum+1)%n;
    }
};

// gas  =   [1,2,3,4], 
// cost =   [2,2,4,1]
// diff =   -1,0,-1,3
// prefix = -1,-1,-2,1

// gas  = [1,2,3], 
// cost = [2,3,2]
// diff = -1 -1 1
// prefix = -1 -2 -1

// 如果prefix <0 => return -1
// 尋找最低點的prefix, 下一個index就是起點

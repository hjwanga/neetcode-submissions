class Solution {
    int dfs(int amount, const vector<int>& coins, int index, vector<vector<int>>& cache) {
        if (amount < 0) {
            return cache[amount][index] = 0;
        }
        if (amount == 0) {
            return cache[amount][index] = 1;
        }
        int n = coins.size();
        if (cache[amount][index] != -1) {
            return cache[amount][index];
        }
        int result = 0;
        for (int i = index; i < n; ++i) {
            int coin = coins[i];
            if (coin > amount) {
                break;
            }
            result += dfs(amount-coin, coins, i, cache);
        }
        return cache[amount][index] = result;
    }
public:
    int change(int amount, vector<int>& coins) {
        // 1. sort in increasing order
        sort(coins.begin(), coins.end());

        // 2.dfs
        int n = coins.size();
        vector<vector<int>> cache(amount+1, vector<int>(n, -1));
        dfs(amount, coins, 0, cache);

        int result = 0;
        for (int num : cache[amount]) {
            if (num == -1) {
                continue;
            }
            result += num;
        }
        return result;
    }
};

// 1. sort + dfs : TLE
// coins = [1,2,3]
// amount                       4
//            (3,0)            (2,1)         (1,2)
//    (2,0)   (1,1) (0,2)      (0,1)           X
// (1,0)(0,1)   X     
//(0,0)   

// 2. DP
// dp[i] := amount i的情況下, 能使用coins[0..n-1]湊出amount的總數
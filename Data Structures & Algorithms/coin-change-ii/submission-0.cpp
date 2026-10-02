class Solution {
public:
    vector<vector<int>> dp;

    int findWays(int amount, int n, vector<int>& coins){
        if(amount == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][amount] != -1) return dp[n][amount];

        int ways = 0;
        if(amount >= coins[n-1])
            ways += findWays(amount-coins[n-1],n,coins);

        ways += findWays(amount, n-1, coins);

        return dp[n][amount] = ways;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp = vector<vector<int>>(n+1, vector<int>(amount+1,-1));
        return findWays(amount, n, coins);
    }
};

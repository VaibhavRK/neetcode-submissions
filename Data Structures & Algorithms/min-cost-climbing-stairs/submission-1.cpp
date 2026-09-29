class Solution {
public:

    int makeStair(int i, vector<int>& cost, vector<int>& dp){
        int n = cost.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(makeStair(i+1, cost, dp), makeStair(i+2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        dp[n] = 0;
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        
        for(int i=n-3;i>=0;i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};

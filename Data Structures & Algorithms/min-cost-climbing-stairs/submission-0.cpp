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
        
        int mn = min(makeStair(0, cost, dp), makeStair(1, cost, dp));

        return mn;
    }
};

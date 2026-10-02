class Solution {
public:
    vector<vector<int>> dp;
    int findProfit(int i, int buy, vector<int>& prices){
        int n = prices.size();

        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int mx = 0;
        if(buy){
            mx = max(mx, findProfit(i+1, 1-buy, prices) - prices[i]);
        }
        else{
            mx = max(mx, findProfit(i+2, 1-buy, prices) + prices[i]);
        }
        mx = max(mx, findProfit(i+1, buy, prices));

        return dp[i][buy] = mx;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp = vector<vector<int>>(n+1, vector<int>(2,-1));
        return findProfit(0, 1, prices);
    }
};

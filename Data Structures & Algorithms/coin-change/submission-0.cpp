class Solution {
public:

    int cal(int amount, vector<int>& coins, vector<int>& dp){
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];
        int mn = 1e7;

        cout<<amount<<endl;

        for(int coin : coins){
            if(amount >= coin){
                mn = min(mn,1 + cal(amount-coin, coins, dp));
                cout<<coin<<" "<<mn<<endl;
            }
        }

        

        return dp[amount] = mn;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1, -1);

        int mn = cal(amount, coins, dp);

        if(mn >= 1e7){
            return -1;
        }

        return mn;
    }
};

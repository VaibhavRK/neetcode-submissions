class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> arr(n);

        int mx = -1;
        for(int i=n-1;i>=0;i--){
            mx = max(prices[i],mx);
            arr[i] = mx;
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            if(prices[i] < arr[i]) ans = max(ans, arr[i] - prices[i]);
        }

        return ans;
    }
};

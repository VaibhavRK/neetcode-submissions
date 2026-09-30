class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n+1,-1);
        dp[n] = 0;
        dp[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }

        int ans = dp[1];

        dp[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }

        return max(ans, dp[0]);
    }
};

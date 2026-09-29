class Solution {
public:
    int robbing(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = max(nums[i] + robbing(i+2, nums, dp), robbing(i+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1,-1);
        dp[n] = 0;
        dp[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }

        return dp[0];
    }
};

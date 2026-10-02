class Solution {
public:
    vector<vector<int>> dp;

    bool check(int n, int sum, vector<int>& nums){
        if(sum == 0) return true;

        if(n == 0) return false;

        if(dp[n][sum] != -1) return dp[n][sum];

        bool ans = false;
        if(nums[n-1] <= sum) ans |= check(n-1, sum-nums[n-1], nums);
        ans |= check(n-1,sum, nums);

        if(ans) dp[n][sum] = 1;
        else dp[n][sum] = 0;

        return ans;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum%2) return false;
        cout<<totalSum<<endl;

        dp = vector<vector<int>>(n+1,vector<int>(totalSum/2+2,-1));

        return check(n, totalSum/2, nums);
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    int findLIS(int n, int m, string& s1, string& s2){
        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        int mx = 0;

        if(s1[n-1] == s2[m-1]){
            mx = findLIS(n-1,m-1,s1,s2)+1;
        }
        mx = max(mx, findLIS(n-1,m,s1,s2));
        mx = max(mx, findLIS(n,m-1,s1,s2));

        return dp[n][m] = mx;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));

        return findLIS(n,m,text1,text2);
    }
};

class Solution {
public:

    vector<vector<int>> dp;

    int cal(int n, int m, string s, string t){
        if(m == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        int ans = 0;

        if(s[n-1] == t[m-1]){
            ans += cal(n-1,m-1,s,t);
        }
        ans += cal(n-1,m,s,t);

        return dp[n][m] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m > n) return 0;
        
        dp = vector<vector<int>>(n+1, vector<int>(m+1,-1));
        return cal(n,m,s,t);
    }
};

class Solution {
public:

    int cal(int i, string& s, vector<int>& dp){
        int n = s.length();
        if(i == n) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];
        
        
        int ans = cal(i+1, s, dp);
        if(i+1 < n){
            if( s[i] - '0' == 2 && s[i+1] - '0' <= 6) ans += cal(i+2, s, dp); 
             if( s[i] == '1') ans += cal(i+2, s, dp); 
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return cal(0, s, dp);
    }
};

class Solution {
public:

    bool check(int i, int j, string& str, unordered_set<string>& wordDict, vector<vector<int>>& dp){
        int n = dp.size();

        if(j == n-1 && wordDict.find(str.substr(i, j-i+1)) != wordDict.end()){
            return true;
        }
        else if(j == n-1) return false;

        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if(wordDict.find(str.substr(i, j-i+1)) != wordDict.end()){
            ans |= check(j+1,j+1,str,wordDict,dp);
        }
        
        ans |= check(i,j+1,str,wordDict,dp);
        if(ans) dp[i][j] = 1;
        else dp[i][j] = 0;

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;

        for(string str : wordDict){
            st.insert(str);
        }

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return check(0,0,s,st,dp);
    }
};

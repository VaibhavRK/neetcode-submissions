class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i=0,j=0;

        vector<int> freq(26,0);
        int ans = 0;
        while(j < n){
            freq[s[j]-'A']++;
            int mx = 0;
            for(int i=0;i<26;i++) mx = max(mx,freq[i]);

            int len = j-i+1;
            if(len-mx > k){
                freq[s[i]-'A']--;
                i++;
            }
            else{
                ans = max(ans,len);
            }
            j++;
        }  

        return ans;      
    }
};

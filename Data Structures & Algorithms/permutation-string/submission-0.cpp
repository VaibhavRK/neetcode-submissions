class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;
        int i=0,j=0;

        vector<int> freq(26,0);

        for(int i=0;i<n1;i++) freq[s1[i]-'a']++;

        while(j < n2){
            if(freq[s2[j]-'a']){
                int temp = j;
                vector<int> checkfreq(26,0);
                while(temp < n2 && temp-j+1 <= n1){
                    checkfreq[s2[temp]-'a']++;
                    temp++;
                }

                bool flag = true;
                for(int u=0;u<26;u++){
                    if(checkfreq[u] != freq[u]){
                        flag = false; break;
                    }
                }

                if(flag) return true;
            }
            j++;
        }

        return false;
    }
};

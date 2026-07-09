class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        if(n == 1) return 1;

        vector<int> v(257,-1);

        int i=0,j=0;
        int mx = 0;

        int left = 0;

        while(j < n){
            if(v[s[j]] == -1 || left > v[s[j]]){
                v[s[j]] = j;
            }
            else{
                mx = max(mx, j-i);
                cout<<i<<" "<<j<<" "<<mx<<endl;
                i = v[s[j]]+1;
                left = i;
                v[s[j]] = j;
            }
            j++;
        }
        cout<<i<<" "<<j<<" "<<mx<<endl;
        // if(i == 0 && j == n)
            mx = max(mx,j-i);

        return mx;
    }
};

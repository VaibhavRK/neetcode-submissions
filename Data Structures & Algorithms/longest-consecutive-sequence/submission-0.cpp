class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        int n = num.size();
        unordered_map<int,int> mp;

        int res = 0;
        for(int i=0;i<n;i++){
           if(!mp[num[i]]){
                mp[num[i]] = mp[num[i]-1] + mp[num[i]+1] + 1;
                mp[num[i] - mp[num[i]-1]] = mp[num[i]];
                mp[num[i] + mp[num[i]+1]] = mp[num[i]];
                res = max(res,mp[num[i]]);
           } 
        }

        return res;
    }
};

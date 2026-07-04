class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(char c : s){
            v1[c-'a']++;
        }

        for(char c : t){
            v1[c-'a']--;
        }

        for(int num : v1){
            if(num) return false;
        }

        return true;
    }
};

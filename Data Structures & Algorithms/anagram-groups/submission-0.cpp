class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> arr(strs.size());
        
        int j = 0;
        for(string str : strs){
            sort(str.begin(), str.end());
            arr[j] = {str, j};
            j++;
        }

        sort(arr.begin(),arr.end());


        vector<vector<string>> ans;

        for(int i=0;i<arr.size();i++){
            vector<string> tmp;
            string str = arr[i].first;
            while( i < arr.size() && str == arr[i].first){
                int idx = arr[i].second;
                tmp.push_back(strs[idx]);
                i++;
            }
            // cout<<" Outside bef "<<i<<endl;
            i--;
            // cout<<" Outside after "<<i<<endl;
            ans.push_back(tmp);
        }

        return ans;
    }
};

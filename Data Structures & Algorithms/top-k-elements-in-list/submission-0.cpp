class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> arr(2002,0);
        int n = nums.size();

        for(int i=0;i<n;i++){
            arr[nums[i]+1000]++;
        }

        vector<pair<int,int>> mapped;

        for(int i=0;i<2002;i++){
            if(!arr[i]) continue;
            mapped.push_back({arr[i], i-1000});
        }

        sort(mapped.begin(), mapped.end());

        vector<int> ans;
        int i = mapped.size()-1;
        while(k--){
            ans.push_back(mapped[i--].second);
        }

        return ans;
    }
};

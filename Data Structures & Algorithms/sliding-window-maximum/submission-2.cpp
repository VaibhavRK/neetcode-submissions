class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        if(k == 1) return nums;

        int left = 0, right = 0;
        int n = nums.size();

        priority_queue<pair<int,int>> pq;

        while(right - left + 1 < k){
            pq.push({nums[right], right});
            right++;
        }
        // ans.push_back(pq.top().first);

        while(right < n){
            pq.push({nums[right],right});
            
            cout<<left<<" ";
            while(!pq.empty() && pq.top().second < left) pq.pop();
            cout<<right<<" "<<pq.top().first<<endl;

            ans.push_back(pq.top().first);
            left++;
            right++;
        }

        return ans;
    }
};

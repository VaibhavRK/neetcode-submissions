class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int lo = 0;
        int hi = n-1;
        int mid;

        while(hi-lo > 1){
            mid = (hi-lo)/2 + lo;

            if(target > nums[mid]) lo = mid+1;
            else hi = mid;
        }

        cout<<hi<<" "<<lo<<endl;

        if(nums[hi] == target) return hi;
        else if(nums[lo] == target) return lo;

        return -1;
    }
};

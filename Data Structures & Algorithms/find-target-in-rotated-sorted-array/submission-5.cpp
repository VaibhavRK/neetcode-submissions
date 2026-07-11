class Solution {
public:
    int binarySearch(int lo, int hi, int target, vector<int>& nums){
        
        int mid;

        while(hi-lo > 1){
            mid = lo + (hi-lo)/2;

            if(target > nums[mid]) lo = mid+1;
            else hi = mid;
        }

        if(nums[hi] == target) return hi;
        else if(nums[lo] == target) return lo;

        return -1;
    }


    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1 && nums[0] == target) return 0;
        else if(n == 1 && nums[0] != target) return -1;
        else if(n == 2){
            if(target == nums[0]) return 0;
            else if(target == nums[1]) return 1;
            return -1;
        }
        int lo = 0;
        int hi = n-1;
        int mid;
        while(hi - lo > 0){
            mid = lo + (hi-lo)/2;

            if(nums[mid] > nums[hi])
                lo = mid+1;
            else 
                hi = mid;
        }
        int pivot = lo;

        if (pivot == 0) {
            return binarySearch(0, n - 1, target, nums);
        } else if (target >= nums[0] && target <= nums[pivot - 1]) {
            return binarySearch(0, pivot - 1, target, nums);
        } else {
            return binarySearch(pivot, n - 1, target, nums);
        }
        
        return -1;
    }
};

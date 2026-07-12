class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int n = nums.size();

        while(fast != slow || (fast == 0 && slow == 0)){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

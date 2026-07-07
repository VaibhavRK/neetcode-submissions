class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i=0;i<n;i++){
            int idx = lower_bound(numbers.begin() + i + 1, numbers.end(), target-numbers[i]) - numbers.begin();
            if(idx == n || numbers[idx] != target-numbers[i]) continue;

            return vector<int>({i+1,idx+1});
        }

        return vector<int>({-1,-1});
    }
};

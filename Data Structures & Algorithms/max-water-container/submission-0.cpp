class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i=0,j=n-1;

        int mx = 0;
        while(i < j){
            mx = max(mx,min(heights[i],heights[j])*(j-i));

            if(heights[i] <= heights[j]){
                i++;
            }
            else j--;
        }

        return mx;
    }
};

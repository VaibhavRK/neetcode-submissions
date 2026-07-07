class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n,-1);
        vector<int> right(n,-1);

        int mx = -1;
        for(int i=0;i<n;i++){
            if(i == 0){
                left[i] = 0;
                mx = max(mx, height[i]);
                continue;
            }
            left[i] = max(mx, height[i]);
            mx = max(mx, height[i]);
        }

        mx = -1;
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                right[i] = 0;
                mx = max(mx, height[i]);
                continue;
            }
            right[i] = max(mx, height[i]);
            mx = max(mx, height[i]);
        }

        int total = 0;

        for(int i=0;i<n;i++){
            int cal = min(left[i],right[i])-height[i];
            if(cal > 0) total += cal;
        }

        return total;
    }
};

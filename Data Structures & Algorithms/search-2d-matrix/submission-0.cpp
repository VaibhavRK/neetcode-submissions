class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        

        int lo = 0;
        int hi = n*m-1;
        int mid;

        while(hi-lo > 1){
            mid = (hi-lo)/2 + lo;

            int i = mid/m;
            int j = mid%m;

            if(target > matrix[i][j]) lo = mid+1;
            else hi = mid;
        }

        if(matrix[hi/m][hi%m] == target) return true;
        else if(matrix[lo/m][lo%m] == target) return true;

        return false;
    }
};

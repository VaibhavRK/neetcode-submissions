class Solution {
public:
    int arr[100];
    int reverse(int n){
        if(n < 0) return 0;
        if(n == 0) return 1; 
        if(arr[n] != -1) return arr[n];

        arr[n] = reverse(n-2) + reverse(n-1);
        return arr[n];
    }

    int climbStairs(int n) {
        for(int i=0;i<100;i++) arr[i] = -1;
        return reverse(n);
    }
};

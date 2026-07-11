class Solution {
public:
    bool checkIsValid(int k, int h, vector<int>& piles){
        int total = 0;

        for(int pile : piles){
            total += (pile/k);
            if(pile%k) total++;
        }

        cout<<total<<endl;

        return total <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int lo = 1;
        int hi = 1e9;

        int mid;

        while(hi - lo > 1){
            mid = (hi-lo)/2 + lo;
            // cout<<mid<<" "<<lo<<" "<<hi<<" ";
            bool flg = checkIsValid(mid, h, piles);
            // cout<<flg<<endl;
            if(!flg) lo = mid+1;
            else hi = mid;
        }

        if(checkIsValid(lo, h, piles)) return lo;
        else if(checkIsValid(hi, h, piles)) return hi;

        return -1;
    }
};

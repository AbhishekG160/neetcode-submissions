class Solution {
public:
    bool eatable(int rate, vector<int>& piles, int time){
        int timeneed = 0;
        for(int& p:piles)
            timeneed += (p/rate) + ((p%rate != 0)?(1):0);
        return (timeneed <= time)?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int soln = 0;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(eatable(mid, piles, h)){
                soln = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return soln;
    }
};

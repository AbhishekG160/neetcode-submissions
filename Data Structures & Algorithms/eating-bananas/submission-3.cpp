class Solution {
public:
    bool helper(int rate, vector<int>& piles, int hours){
        long long hoursneed = 0;
        for(int& p:piles)
            hoursneed += (p/rate) + ((p%rate != 0)?1:0);
        return (hoursneed <= hours)?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minrate = 1;
        int maxrate = *max_element(piles.begin(), piles.end());
        int result = 0;
        while(minrate <= maxrate){
            int mid = minrate + (maxrate-minrate)/2;
            if(helper(mid, piles, h)){
                result = mid;
                maxrate = mid-1;
            }
            else minrate = mid+1;
        }
        return result;
    }
};

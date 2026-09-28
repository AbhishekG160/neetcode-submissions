class Solution {
    // bool possible(int maxcap, int days, vector<int>& weights){
    //     int daysneed = 1;
    //     int capleft = maxcap;
    //     for(int& w:weights){
    //         if(capleft - w < 0){ // current parcel overloads so add another day with fresh cap
    //             daysneed++;
    //             if(daysneed > days) return false;
    //             capleft = maxcap;
    //         }
    //         capleft -= w;
    //     }
    //     return true;
    // }
    bool check(int cap, vector<int>& weights, int limit){
        int maxm = cap;
        int ships = 1;
        for(int& w:weights){
            if(maxm-w < 0){
                // this goes on next ship
                ships++;
                if(ships > limit)
                    return false;
                maxm = cap;
            }
            maxm -= w;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // int minm = *max_element(weights.begin(), weights.end());
        // int maxm = accumulate(weights.begin(), weights.end(), 0);
        // int capacity = maxm;
        // while(minm <= maxm){
        //     int mid = minm+(maxm - minm)/2;
        //     if(possible(mid, days, weights)){
        //         capacity = mid;
        //         maxm = mid-1;
        //     }
        //     else minm = mid+1;
        // }
        // return capacity;

        int minm = *max_element(weights.begin(), weights.end());
        int maxm = accumulate(weights.begin(), weights.end(), 0);
        int rescap = maxm;
        while(minm <= maxm){
            int mid = minm+(maxm-minm)/2;
            if(check(mid, weights, days)){
                rescap = mid;
                maxm = mid-1;
            }
            else minm = mid+1;
        }
        return rescap;
    }
};
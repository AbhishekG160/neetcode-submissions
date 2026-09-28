class Solution {
public:
    bool possible(int summ, vector<int>& nums, int k){
        int maxm = summ;
        int subs = 1;
        for(int& n:nums){
            if(maxm-n < 0){
                // this goes into another subarray
                subs++;
                if(subs > k)
                    return false;
                maxm = summ;
            }
            maxm -= n;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int minm = *max_element(nums.begin(), nums.end());
        int maxm = accumulate(nums.begin(), nums.end(), 0);
        int minres = maxm;
        while(minm <= maxm){
            int mid = minm + (maxm-minm)/2;
            if(possible(mid, nums, k)){
                maxm = mid-1;
                minres = mid;
            }
            else minm = mid+1;
        }
        return minres;
    }
};
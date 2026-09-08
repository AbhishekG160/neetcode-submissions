class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // either the maxm subarr is inside the boundary -> maxm sum kadane --> result
        // or the maxm subarr is wrapped around boundary -> total sum - minm sum kadane --> result
        int curr = -1e8;
        int maxsum = -1e8;
        int curr2 = 1e9;
        int minsum = 1e9;
        int totalsum = 0;
        for(int i=0; i<nums.size(); i++){
            curr = max(curr+nums[i] , nums[i]);
            maxsum = max(curr , maxsum);
            curr2 = min(curr2+nums[i] , nums[i]);
            minsum = min(curr2 , minsum);
            totalsum += nums[i];
        }
        if(maxsum < 0)
            return maxsum; // else the actual logic will give 0 for all negative
        return max(maxsum , totalsum - minsum);        
    }
};
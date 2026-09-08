class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = -1e8;
        int maxsum = -1e8;
    
        for(int i=0; i<nums.size(); i++){
            curr = max(curr+nums[i], nums[i]);
            maxsum = max(maxsum, curr);
        }
        return maxsum;    
    }
};

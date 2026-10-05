class Solution {
public:
    int help(vector<int>& nums, int idx, int xorval){
        if(idx >= nums.size())
            return xorval;
        return help(nums, idx+1, xorval) + help(nums, idx+1, xorval^nums[idx]);
    }
    int subsetXORSum(vector<int>& nums) {
        return help(nums, 0, 0);
    }
};
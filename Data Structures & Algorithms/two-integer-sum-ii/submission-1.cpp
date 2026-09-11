class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            if(nums[l] + nums[r] == t) 
                {return {l+1, r+1};}
            else if(nums[l]+nums[r] < t)
                l++;
            else r--;
        }
        return {l+1, r+1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> complement;
        for(int i=0; i<n; i++){
            int compli = target - nums[i];
            if(complement.find(compli) != complement.end())
                return {complement[compli] , i};
            complement[nums[i]] = i;  
        }
        return {};
    }
};

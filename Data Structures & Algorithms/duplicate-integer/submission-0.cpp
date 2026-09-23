class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> exist;
        for(int i=0; i<nums.size(); i++){
            if(exist.count(nums[i]))
                return true;
            exist.insert(nums[i]);
        }
        return false;
    }
};
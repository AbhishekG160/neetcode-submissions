class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& curr, vector<int>& nums, int target, int sum, int idx){
        if(sum == target){
            result.push_back(curr);
            return;
        }
        if(sum>target || idx >= nums.size())
            return;
        curr.push_back(nums[idx]);
        helper(result, curr, nums, target, sum+nums[idx], idx);
        curr.pop_back();
        helper(result, curr, nums, target, sum, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(result, curr, nums, target, 0, 0);
        return result;
    }
};

class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int idx){
        if(idx == nums.size()){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        helper(nums, result, curr, idx+1);
        curr.pop_back();
        helper(nums, result, curr, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(nums, result, curr, 0);
        return result;
    }
};

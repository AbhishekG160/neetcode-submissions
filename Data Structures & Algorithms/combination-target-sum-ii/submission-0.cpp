class Solution {
public:
    void helper(vector<vector<int>>& results, vector<int>& curr, int target, vector<int>& nums, int idx){
        if(target == 0){
            results.push_back(curr);
            return;
        }
        if(idx == nums.size())
            return;
        if (nums[idx] > target)
            return;
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1])
                continue;
            if(nums[i]>target)
                break;
            curr.push_back(nums[i]);
            helper(results, curr, target-nums[i], nums, i+1);
            curr.pop_back();            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int>curr;
        helper(results, curr, target, candidates, 0);
        return results;
    }
};

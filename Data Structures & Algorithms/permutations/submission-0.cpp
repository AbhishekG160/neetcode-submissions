class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& curr, vector<int>& vis, vector<int>& nums){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(vis[i])
                continue;
            vis[i] = true;
            curr.push_back(nums[i]);
            helper(res, curr, vis, nums);
            vis[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<int> visited(nums.size(), false);
        helper(result, curr, visited, nums);
        return result;
    }
};

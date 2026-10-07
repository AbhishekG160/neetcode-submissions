class Solution {
public:
    // void helper(vector<vector<int>>& res, vector<int>& curr, vector<int>& vis, vector<int>& nums){
    //     if(curr.size() == nums.size()){
    //         res.push_back(curr);
    //         return;
    //     }
    //     for(int i=0; i<nums.size(); i++){
    //         if(vis[i])
    //             continue;
    //         vis[i] = true;
    //         curr.push_back(nums[i]);
    //         helper(res, curr, vis, nums);
    //         vis[i] = false;
    //         curr.pop_back();
    //     }
    // }
    void helper(vector<vector<int>>& result, vector<int>& nums, int idx){
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            helper(result, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        // vector<int> curr;
        // vector<int> visited(nums.size(), false);
        // helper(result, curr, visited, nums);
        // return result;
        vector<int> curr(nums.begin(), nums.end());
        helper(result, curr, 0);
        return result;
    }
};

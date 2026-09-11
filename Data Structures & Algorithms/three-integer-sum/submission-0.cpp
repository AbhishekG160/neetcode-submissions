class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        int n = nums.size();
        for(int t=0; t<n-2; t++){
            if(nums[t] > 0) 
                continue;
            if(t>0 && nums[t]==nums[t-1])
                continue;
            int i = t+1;
            int j = n-1;
            while(i<j){
                int sum = nums[t]+nums[i]+nums[j];
                if(sum == 0){
                    results.push_back({nums[t] ,nums[i] ,nums[j]});
                    // removing duplicates
                    while(i<j && nums[i] == nums[i+1])
                        i++;
                    while(j>i && nums[j] == nums[j-1])
                        j--;
                    // go for next pair
                    i++;
                    j--; 
                }
                else if(sum < 0) i++;
                else j--;
            }
        }
        return results;
    }
};

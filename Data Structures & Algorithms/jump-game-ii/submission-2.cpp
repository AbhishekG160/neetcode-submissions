class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int minstep = 1e9;
            for(int j=i+1; j<=min(n-1, nums[i]+i); j++){
                minstep = min(minstep , 1+dp[j]);
            }
            dp[i] = minstep;
        }
        return dp[0];
    }
};

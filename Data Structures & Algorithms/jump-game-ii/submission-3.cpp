class Solution {
public:
    int jump(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n, 1e9);
        // dp[n-1] = 0;
        // for(int i=n-2; i>=0; i--){
        //     int minstep = 1e9;
        //     for(int j=i+1; j<=min(n-1, nums[i]+i); j++){
        //         minstep = min(minstep , 1+dp[j]);
        //     }
        //     dp[i] = minstep;
        // }
        // return dp[0];

        int n = nums.size();
        int currmax = 0;
        int farthest = 0;
        int jumps = 0;
        for(int i=0; i<n-1; i++){
            farthest = max(farthest , i+nums[i]);
            if(i == currmax){
                currmax = farthest;
                jumps++;
                if(currmax >= n-1)
                    break;
            }
        }
        return jumps;
    }
};

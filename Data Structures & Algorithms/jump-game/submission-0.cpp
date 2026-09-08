class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> reachable(n, false);
        reachable[n-1] = true;
        for(int i=n-2; i>=0; i--){
            int limit = min(n-1, i+nums[i]);
            for(int j=i+1; j<=limit; j++){
                if(reachable[j]){
                    reachable[i] = true;
                    break;
                }
            }
        }
        return reachable[0];
    }
};

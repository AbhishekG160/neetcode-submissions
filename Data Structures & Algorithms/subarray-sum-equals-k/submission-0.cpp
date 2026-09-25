class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum_count;
        presum_count[0] = 1;
        int n = nums.size();
        int count = 0;
        int runningsum = 0;
        for(int i=0; i<n; i++){
            runningsum += nums[i];
            if(presum_count.find(runningsum - k) != presum_count.end()){
                count += presum_count[runningsum - k];
            }
            presum_count[runningsum]++;
        }
        return count;
    }
};
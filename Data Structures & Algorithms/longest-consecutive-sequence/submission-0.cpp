class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sequence(nums.begin(), nums.end());
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            if(sequence.count(nums[i]-1))
                continue;
            int currlen = 1;
            int elem = nums[i];
            while(sequence.count(elem+1)){
                currlen += 1;
                elem = elem+1;
            }
            result = max(result, currlen);
        }
        return result;
    }
};

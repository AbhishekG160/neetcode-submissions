class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& n:nums)
            freq[n]++;
        vector<int> result;
        int n = nums.size();
        n = n/3;
        for(auto& pair:freq)
            if(pair.second > n)
                result.push_back(pair.first);
        return result;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int& n:nums)
            freq[n]++;
        
        unordered_map<int, vector<int>> buckets;
        for(auto& pair:freq)
            buckets[pair.second].push_back(pair.first);
        
        vector<int> result;
        for(int bucket = nums.size(); bucket>0; bucket--){
            for(int elem = 0; elem<buckets[bucket].size(); elem++){
                result.push_back(buckets[bucket][elem]);
                if(result.size() == k)
                    return result;
            }
        }
        return result;
    }
};

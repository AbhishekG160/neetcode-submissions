class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        // value , frequency
        for(int num:nums)
            freq[num]++;
        
        vector<vector<int>> freqbucket(n+1);
        // freq from 1 to n
        // freq -> [elements having this freq]
        for(auto& pair:freq){
            int f = pair.second;
            freqbucket[f].push_back(pair.first);
        }

        vector<int> result;
        for(int bucket = n; bucket>=1; bucket--){
            for(int val = 0; val<freqbucket[bucket].size(); val++){
                result.push_back(freqbucket[bucket][val]);
                if(result.size() == k)
                    return result;
            }
        }
        return result;
    }
};

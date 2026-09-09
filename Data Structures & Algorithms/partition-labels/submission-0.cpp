class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> last_appear(26, 0);
        for(int i=0; i<n; i++)
            last_appear[s[i] - 'a'] = i;
        // x khatam hoga 3 index pe
        // y khatam hoga 4 index pe
        
        vector<int> result; // store partitions size
        int start = 0;
        int end = 0;
        for(int i=0; i<n; i++){
            end = max(end, last_appear[s[i]-'a']);
            if(i == end){ // this is the end of the partition 
                result.push_back(end+1 - start);
                start = i+1;
            }
        }
        return result;
    }
};

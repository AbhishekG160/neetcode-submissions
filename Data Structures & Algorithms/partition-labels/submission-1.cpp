class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastseen;
        int n = s.length();
        for(int i=0; i<n; i++)
            lastseen[s[i]-'a'] = i;

        int start=0, end=0;
        // start and ending of a partition
        vector<int> result; 
        for(int i=0; i<n; i++){
            end = max(end, lastseen[s[i]-'a']);
            if(i == end){
                // partition found
                result.push_back(end+1-start);
                start = i+1;
            }
        } 
        return result;
    }
};

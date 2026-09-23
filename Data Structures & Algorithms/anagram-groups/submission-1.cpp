class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sortedword;
        // for(string& str:strs){
        //     string s = str;
        //     sort(s.begin(), s.end());
        //     sortedword[s].push_back(str);
        // }

        for(string& str:strs){
            vector<int> count(26,0);
            for(char c:str)
                count[c-'a']++;
            string key = "";
            for(int c:count)
                key += '*'+(char)(c+'a');
            sortedword[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& pair:sortedword){
            vector<string> words = pair.second;
            result.push_back(words);
        }
        return result;
    }
};

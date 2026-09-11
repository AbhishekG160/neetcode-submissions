class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0;
        int n = word1.length(), m = word2.length();
        string result = "";
        while(i<n && j<m){
            if(result.size() %2)
                result.push_back(word2[j++]);
            else result.push_back(word1[i++]);
        }
        while(i<n) 
            result.push_back(word1[i++]);
        while(j<m)
            result.push_back(word2[j++]);
        return result;
    }
};
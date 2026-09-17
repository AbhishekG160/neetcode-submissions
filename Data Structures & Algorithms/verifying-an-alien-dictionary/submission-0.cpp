class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> idx;
        for(int i=0; i<order.size(); i++)
            idx[order[i]] = i;
        for(int i=0; i<words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            if(word1.length()>word2.length() && word1.substr(0, word2.length()) == word2)   
                return false;
            for(int j=0; j<min(word1.length(), word2.length()); j++){
                if(idx[word1[j]] > idx[word2[j]])
                    return false;
                else if(idx[word1[j]] < idx[word2[j]])
                    break;
            }
        }
        return true;
    }
};
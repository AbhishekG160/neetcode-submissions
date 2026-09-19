class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string curr = q.front().first;
            int level = q.front().second;
            q.pop();
            if(curr == endWord)
                return level;
            for(int i=0; i<curr.size(); i++){
                char org = curr[i];
                for(char j = 'a'; j<='z'; j++){
                    if(j == org) continue;
                    curr[i] = j;
                    if(words.find(curr) != words.end()){
                        q.push({curr, level+1});
                        words.erase(curr);
                    }
                }
                curr[i] = org;
            }
        }
        return 0;
    }
};

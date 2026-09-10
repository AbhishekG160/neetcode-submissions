class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        // tracks words used
        queue<pair<string, int>> q;
        // BFS with the level number
        q.push({beginWord, 1});
        st.erase(beginWord);
        
        // bfs
        while(!q.empty()){
            string curr = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(curr == endWord)     
                return lev;
            
            for(int i=0; i<curr.length(); i++){
                char org = curr[i];
                for(char c='a'; c<='z'; c++){
                    curr[i] = c;
                    if(st.find(curr) != st.end()){
                        q.push({curr, lev+1});
                        st.erase(curr);
                    }
                }
                curr[i] = org;    
            }
        }
        return 0;
    }
};

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, -1); // -1 -> char not used

        for(string& word:words)
            for(char w:word)
                if(indeg[w-'a'] == -1)
                    indeg[w-'a'] = 0;

        // create adj and indeg
        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            if(w1.length()>w2.length() && w1.substr(0, w2.length()) == w2)
                return "";
            int minlen = min(w1.length(), w2.length());
            for(int j=0; j<minlen; j++)
                if(w1[j] != w2[j]){
                    int u = w1[j]-'a';
                    int v = w2[j]-'a';
                    if(find(adj[u].begin(), adj[u].end(), v) == adj[u].end()){
                        adj[u].push_back(v);
                        indeg[v]++;
                    }
                    break;
                }
        }

        // mark nodes with 0 indeg
        queue<int> q;
        int totals = 0;
        for(int i=0; i<26; i++){
            if(indeg[i] != -1){
                totals++;
                if(indeg[i] == 0)
                    q.push(i);
            }
        }

        // bfs kahn
        string result = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result += (char)(curr + 'a');

            for (int neighbor : adj[curr]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if(result.size() != totals)
            return "";
        return result;
    }
};

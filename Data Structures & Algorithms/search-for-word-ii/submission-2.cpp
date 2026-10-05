class Solution {
    struct trienode{
        string word = "";
        // bool leaf;
        trienode* children[26];
        trienode(){
            // leaf = false;
            for(int i=0; i<26; i++)
                children[i] = nullptr;
        }
    };
    void insert(string& word, trienode* root){
        trienode* curr = root;
        for(char& c:word){
            int idx = c-'a';
            if(!curr->children[idx])
                curr->children[idx] = new trienode();
            curr = curr->children[idx];
        }
        // curr->leaf = true;
        curr->word = word;
    }

    void dfs(int r, int c, trienode* curr, vector<vector<char>>& board, vector<string>& result){
        char ch = board[r][c]; // get word
        int idx = ch-'a'; 
        if(ch=='#' || !curr->children[idx])
            return; 
            // if already visited or child not existed from this node to the char 
        
        trienode* child = curr->children[idx];
        // go to child node
        if(!child->word.empty()){ // word exists here
            result.push_back(child->word);
            child->word = "";   // prevent duplicates entries
        }

        board[r][c] = '#'; // mark visited

        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size())
                dfs(nr, nc, child, board, result);
        }

        board[r][c] = ch; // reset to original

        // extra pruning logic 
        // if all child's all further nodes are traversed and its word is added to list if it had any
        // then we dont need to go here again
        bool childleft = false;
        for(int i=0; i<26; i++)
            if(child->children[i]){
                childleft = true;
                break;
            }
        if(!childleft && child->word.empty()){
            delete child;
            curr->children[idx] = nullptr;
        }
    }
    
    trienode* root;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new trienode();
        for(string& word:words)
            insert(word, root);

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                dfs(i, j, root, board, result);
        return result;
    }
};

class WordDictionary {
    struct trienode{
        bool leaf;
        trienode* children[26];
        trienode(){
            leaf = false;
            for(int i=0; i<26; i++)
                children[i] = nullptr;
        }
    };
    trienode* root;
    bool searcher(string& word, int idx, trienode* curr){
        if(!curr)
            return false;
        if(idx == word.length())
            return curr->leaf;
        
        if(word[idx] != '.'){
            int charidx = word[idx]-'a';
            return searcher(word, idx+1, curr->children[charidx]);
        }
        else{
            for(int i=0; i<26; i++)
                if(curr->children[i] && searcher(word, idx+1, curr->children[i]))
                    return true;
            return false;
        }
    }
public:
    WordDictionary() {
        root = new trienode();
    }
    void addWord(string word) {
        trienode* curr = root;
        for(char& c:word){
            int idx = c-'a';
            if(!curr->children[idx])
                curr->children[idx] = new trienode();
            curr = curr->children[idx];
        }
        curr->leaf = true;
    }
    bool search(string word) {
        return searcher(word, 0, root);
    }
};

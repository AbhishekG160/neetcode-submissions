class PrefixTree {
    struct trienode{
        bool leaf;
        trienode* children[26];
        trienode(){
            leaf = false;
            for(int i=0; i<26; i++)
                children[i] = nullptr;
        }
    };
    
    bool searcher(string& word, int idx, trienode* curr){
        if(!curr)
            return false;
        if(idx == word.length())
            return curr->leaf;
        
        int charidx = word[idx]-'a';
        return searcher(word, idx+1, curr->children[charidx]);  
    }
    bool prefind(string& word, int idx, trienode* curr){
        if(!curr)
            return false;
        if(idx == word.length())
            return true;
        int charidx = word[idx]-'a';
        return prefind(word, idx+1, curr->children[charidx]);
    }

    trienode* root;
public:
    PrefixTree() {
        root = new trienode();
    }
    
    void insert(string word) {
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
    
    bool startsWith(string prefix) {
        return prefind(prefix, 0, root);
    }
};

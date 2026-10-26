class LRUCache {
private:
    int cap;
    struct node{
        int key, val;
        node *next, *prev;
        node(int k, int v):key(k), val(v), next(nullptr), prev(nullptr){}
    };
    node *head, *tail;
    unordered_map<int , node*> mmap;
    void addtohead(node* curr){
        curr->next = head->next;
        head->next = curr;
        curr->prev = head;
        if(curr->next)
            curr->next->prev = curr;
    }
    void movetohead(node* curr){
        remove(curr);
        addtohead(curr);
    }
    void remove(node* curr){
        node* p = curr->prev;
        node* n = curr->next;
        p->next = n;
        n->prev = p;
    }
    void removelru(){
        node* removal = tail->prev;
        mmap.erase(removal->key);
        remove(removal);
    }
public:
    LRUCache(int capacity):cap(capacity) {
        head = new node(-1, 0);
        tail = new node(-1, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mmap.find(key) == mmap.end())
            return -1;
        node *curr = mmap[key];
        movetohead(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        // already existing 
        if(mmap.find(key) != mmap.end()){
            node* curr = mmap[key];
            curr->val = value;
            movetohead(curr);
        } else {
            // not existing -> need to add node
            if(mmap.size() == cap)
                removelru();
            node* newone = new node(key, value);
            addtohead(newone);
            mmap[key] = newone;
        }
    }
};

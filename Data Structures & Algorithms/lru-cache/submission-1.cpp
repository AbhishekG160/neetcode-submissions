class LRUCache {
private:
    struct node{
        int val, key;
        node* next, *prev;
        node(int v, int k):val(v), key(k), next(nullptr), prev(nullptr){}
    };

    node* head, *tail;
    int cap;
    unordered_map<int,node*> mapp;

    void movetohead(node* curr){
        removenode(curr);
        addtohead(curr);
    }
    void removenode(node* curr){
        node* prevnode = curr->prev;
        node* nextnode = curr->next;
        prevnode->next = nextnode;
        nextnode->prev =  prevnode;
    }
    void addtohead(node* curr){
        curr->next = head->next;
        curr->prev = head;
        head->next = curr;
        if(curr->next)
            curr->next->prev = curr;
    }
    void removelru(){
        node* removal = tail->prev;
        mapp.erase(removal->key);
        removenode(removal);
    }
public:
    LRUCache(int capacity):cap(capacity) {
        head = new node(-1, 0);
        tail = new node(-1, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mapp.find(key) == mapp.end())
            return -1;
        node* curr = mapp[key];
        movetohead(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(mapp.find(key) != mapp.end()){
            node* node = mapp[key];
            node->val = value;
            movetohead(node);
        }
        else{
            // value need to be added
            // if size reached hte cap remove one and then add
            if(mapp.size() == cap)
                removelru();
            node* curr = new node(value, key);
            addtohead(curr);
            mapp[key] = curr;
        }        
    }
};

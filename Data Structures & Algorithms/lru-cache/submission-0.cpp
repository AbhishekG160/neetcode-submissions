class LRUCache {
    struct Node{
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int k, int v):key(k), val(v), next(nullptr), prev(nullptr){}
    };
    int cap;
    unordered_map<int, Node*> nodelist;
    Node* head;
    Node* tail; 
    void addtohead(Node* node){
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }
    void removenode(Node* node){
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }
    void movetohead(Node* node){
        removenode(node);
        addtohead(node);
    }
    Node* lruremove(){
        Node* node = tail->prev;
        removenode(node);
        return node;
    }
public:
    LRUCache(int capacity):cap(capacity) {
        head = new Node(-1 , -1);
        tail = new Node(-1 , -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(nodelist.find(key) == nodelist.end())
            return -1;
        Node* node = nodelist[key];
        movetohead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(nodelist.find(key) != nodelist.end()){
            Node* node = nodelist[key];
            node->val = value;
            movetohead(node);
        } else {
            if(nodelist.size() == cap){
                Node* node = lruremove();
                nodelist.erase(node->key);
                delete node;
            }
            Node* node = new Node(key, value);
            addtohead(node);
            nodelist[key] = node;
        }
    }
};

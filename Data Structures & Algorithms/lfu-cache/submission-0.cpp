class LFUCache {
    struct Node{
        int key;
        int val;
        list<int>::iterator iter;
        int freq;
    };
    int capacity;
    unordered_map<int, list<int>> freqtolist;
    unordered_map<int, Node> keytonode;
    int minf;  
    void Ufreq(int key){
        Node& node = keytonode[key];
        freqtolist[node.freq].erase(node.iter); // remove node from list
        // if hte list is empty now -> remove the list 
        if(freqtolist[node.freq].empty()){
            freqtolist.erase(node.freq);
            if(node.freq == minf)
                minf++;
        }
        node.freq++;
        freqtolist[node.freq].push_front(node.key); // current key - most recent - at the front
        node.iter = freqtolist[node.freq].begin();
    }
public:
    LFUCache(int capacity):capacity(capacity), minf(0) {}
    
    int get(int key) {
        if(keytonode.find(key) == keytonode.end() || capacity == 0)
            return -1;
        Ufreq(key);
        return keytonode[key].val;
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;
        if(keytonode.find(key) != keytonode.end()){
            // already there -> update val, update freq
            keytonode[key].val = value;
            Ufreq(key);
            return;
        }
        
        if(capacity == keytonode.size()){
            int removekey = freqtolist[minf].back(); // select the min freq and least recent key
            freqtolist[minf].pop_back();             // remove from list
            if(freqtolist[minf].empty())             // if the only in list -> remove this minf mapping
                freqtolist.erase(minf);
            keytonode.erase(removekey);              // remove the key from key to node mapping
        }

        minf = 1;
        // add the node with freq of 1
        freqtolist[1].push_front(key);
        keytonode[key] = {key, value, freqtolist[1].begin(), 1};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
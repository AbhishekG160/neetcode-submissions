class MyHashSet {
    vector<list<int>> buckets;
    int bucketnum = 769;
    int hash(int n){
        return n%bucketnum;
    }
public:
    MyHashSet() {
        buckets.resize(bucketnum);
    }
    
    void add(int key) {
        int hashed = hash(key);
        auto& bucket = buckets[hashed];
        if(find(bucket.begin(), bucket.end(), key) == bucket.end())
            bucket.push_back(key);
    }
    
    void remove(int key) {
        int hashed = hash(key);
        auto& bucket = buckets[hashed];
        auto it = find(bucket.begin(), bucket.end(), key);
        if(it != bucket.end())
            bucket.erase(it);
    }
    
    bool contains(int key) {
        int hashed = hash(key);
        auto& bucket = buckets[hashed];
        if(find(bucket.begin(), bucket.end(), key) != bucket.end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
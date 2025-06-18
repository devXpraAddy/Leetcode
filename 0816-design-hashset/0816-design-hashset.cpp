class MyHashSet {
public:
    vector<list<int>>buckets;
    int size = 10000;

    MyHashSet() {
        buckets.resize(size);
    }
    
    void add(int key) {
        int bucket_no = key%size;
        auto &chain = buckets[bucket_no];
        for(auto it: chain){
            if(it == key) return ;
        }
        chain.push_back(key);
    }
    
    void remove(int key) {
        int bucket_no = key%size;
        auto &chain = buckets[bucket_no];
        
        for(auto it = chain.begin(); it != chain.end(); it++){
            if(*it == key){
                chain.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int bucket_no = key%size;
        auto &chain = buckets[bucket_no];

        for(auto it: chain){
            if(it == key) return true;
        }
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
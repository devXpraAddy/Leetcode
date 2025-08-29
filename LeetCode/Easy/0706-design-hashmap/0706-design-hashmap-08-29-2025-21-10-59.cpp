class MyHashMap {
public:
    int M;
    vector<list<pair<int,int>>>buckets;

    MyHashMap() {
        M = 15000;
        buckets = vector<list<pair<int,int>>>(M, list<pair<int,int>>{});    
    }

    int hash(int key){
        return key%M;
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        for(auto it = buckets[idx].begin(); it != buckets[idx].end(); it++){
            if(it->first == key){
                it->second = value;
                return; // don't forget to return if key already exists
            }
        }
        buckets[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);

        for(auto it = buckets[idx].begin(); it != buckets[idx].end(); it++){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        for(auto it = buckets[idx].begin(); it != buckets[idx].end(); it++){
            if(it->first == key){
                buckets[idx].erase(it);
                return; // don't forget the return else iterator will show err
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
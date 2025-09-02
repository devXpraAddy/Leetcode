// class Node {
// public:
//     int val;
//     int key;
//     Node* next;
//     Node* prev;

//     Node(int key, int val) {
//         this->val = val;
//         this->key = key;
//         next = NULL;
//         prev = NULL;
//     }
// };

class LRUCache {
public:
    class Node {
    public:
        int val;
        int key;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->val = val;
            this->key = key;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int capacity;

    void addNode(Node* newNode) { // will always add the new node
        // in head's next (MRU)
        Node* oldNode = head->next;
        head->next = newNode;
        oldNode->prev = newNode;
        newNode->next = oldNode;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // In get: First we have to get the corresponding val of key
    // Then the node which we are getting should be moved to most recently used

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* ansNode = mp[key];
        int ans = mp[key]->val;
        // making it most recent node
        mp.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) { // while inserting if the key is already
            // present in the map but the val is differnet in that case we will
            // delete the node
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
        }
        if (mp.size() == capacity) { // if the capacity is reached then we will
            // always delete from the end
            // delete LRU data
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        // 1
        Node* newNode = new Node(key, value);
        addNode(newNode);  // new node will always be added in head's next
        mp[key] = newNode; // adding new node in map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
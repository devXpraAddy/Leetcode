class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    int n;
    MyLinkedList() {
        head = new Node(0);
        n = 0;
    }
    
    int get(int index) {
        if(index >= n) return -1;
        Node* curr = head->next;

        for(int i =0;i<index; i++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(n, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > n) return;
        Node* curr = head;
        for(int i =0; i<index; i++){
            curr = curr->next;
        }
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        n++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= n) return;
        Node* curr = head;
        for(int i=0;i<index; i++){
            curr = curr->next;
        }
        Node* del = curr->next;
        curr->next = curr->next->next;
        delete(del);
        n--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
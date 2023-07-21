class LRUCache {
private:
    class node{
        public:
        int key , val;
        node* prev;
        node* next;
        node(int k ,int v){
            key = k , val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int , node*> keyMap;
    node* head , *tail;

    void addnode(node* ptr){
        ptr->prev = head;
        ptr->next = head->next;
        head->next->prev = ptr;
        head->next = ptr;
    }

    void delnode(node* ptr){
        node* prevn = ptr->prev;
        node* nextn = ptr->next;
        prevn->next = nextn;
        nextn->prev = prevn;
        ptr->next = ptr->prev = nullptr;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1 , -1);
        tail = new node(-1 , -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(keyMap.find(key) != keyMap.end()){
            node* resnode = keyMap[key];
            int res = resnode->val;
            delnode(resnode);
            addnode(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyMap.find(key) != keyMap.end()){
            node* resnode = keyMap[key];
            keyMap.erase(key);
            delnode(resnode);
        }
        if(keyMap.size() == cap){
            int tempKey = tail->prev->key;
            delnode(tail->prev);
            keyMap.erase(tempKey);
        }
        addnode(new node(key , value));
        keyMap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
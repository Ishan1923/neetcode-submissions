class Node{
    public:
        int val;
        int key;
        Node* next;
        Node* prev;
        Node() : val(0), key(0), next(nullptr), prev(nullptr) {}
        Node(int key_, int val_) : val(val_), key(key_), next(nullptr), prev(nullptr) {}
        Node(int key_, int val_, Node* next_, Node* prev_) : val(val_), key(key_), next(next_), prev(prev_) {}

        ~Node(){}
};

class LRUCache {

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void insert(Node* node){

        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;

    }

    void remove(Node* node){

        Node* node_prev = node->prev;
        Node* node_next = node->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;

    }

    void make_space(){
        Node* least_used = tail->prev;
        Node* least_used_prev = least_used->prev;
        least_used_prev->next = tail;
        tail->prev = least_used_prev;

        cache.erase(least_used->key);

        delete least_used;
    }


public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){

            Node* node = cache[key];

            remove(node);
            insert(node);

            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;
            cache[key]->val = value; //is this redundant?
        }
        else{
            if(cache.size() == this->capacity){
                make_space();
            }
            Node* new_node = new Node(key, value);
            insert(new_node);
            cache[key] = new_node;
        }
    }
};

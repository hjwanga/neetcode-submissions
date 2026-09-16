class LRUCache {
    struct Node {
        Node() = default;
        Node(int k, int v, Node* p, Node* n): key(k), value(v), prev(p), next(n){}
        int key;
        int value;
        Node* prev;
        Node* next;
    };
    Node left;
    Node right;
    unordered_map<int, Node*> nodes;
    int capacity;

    // remove node from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->prev = nullptr;
        node->next = nullptr;
    }
    // insert node to rightmost
    void insert(Node* node) {
        Node* prev = right.prev;
        Node* next = &right;
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }
public:
    LRUCache(int capacity):capacity(capacity) {
        left.next = &right;
        right.prev = &left;
    }
    
    int get(int key) {
        if (!nodes.count(key)) {
            return -1;
        }
        // remove node
        remove(nodes[key]);
        // insert to rightmost
        insert(nodes[key]);
        return nodes[key]->value;
    }
    
    void put(int key, int value) {
        if (nodes.count(key)) {
            remove(nodes[key]);
            insert(nodes[key]);
            nodes[key]->value = value;
            return;
        }
        nodes[key] = new Node(key, value, nullptr, nullptr);
        insert(nodes[key]);
        if ((int)nodes.size() > capacity) {
            Node* odd = left.next;
            nodes.erase(odd->key);
            remove(odd);
            delete odd;
        }
    }
};

// unordered_map<int, Node*>
// Node left;
// Node right;
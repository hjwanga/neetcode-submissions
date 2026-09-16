class LRUCache {
    struct Node {
        Node() = default;
        Node(int k, int v, Node* p, Node* n): key(k), value(v), prev(p), next(n){}
        int key;
        int value;
        Node* prev;
        Node* next;
    };
    Node head;
    Node tail;
    int capacity;
    // <key, node>
    unordered_map<int, Node*> nodes;
public:
    LRUCache(int capacity):capacity(capacity) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    // remove from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    // insert at rightmost
    void insert(Node* node) {
        Node* prev = tail.prev;
        Node* next = &tail;
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }

    void update_to_rightmost(Node* node) {
        remove(node);
        insert(node);
    }

    int get(int key) {
        if (!nodes.count(key)) {
            return -1;
        }
        update_to_rightmost(nodes[key]);
        return nodes[key]->value;
    }
    
    void put(int key, int value) {
        if (nodes.count(key)) {
            nodes[key]->value = value;
            update_to_rightmost(nodes[key]);
            return;
        }
        nodes[key] = new Node(key, value, nullptr, nullptr);
        // inser to rightmost
        insert(nodes[key]);
        
        if ((int)nodes.size() > capacity) {
            // remove leftmost node
            Node* leftmost_node = head.next;
            remove(leftmost_node);
            nodes.erase(leftmost_node->key);
            delete leftmost_node;
        }
    }
};

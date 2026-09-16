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
    int capacity;
    unordered_map<int, Node*> nodes;
public:
    LRUCache(int capacity):capacity(capacity) {
        left.next = &right;
        right.prev = &left;
    }
    
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    // inser at the rightmost
    void insert(Node* node) {
        Node* prev = right.prev;
        Node* next = &right;
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
        insert(nodes[key]);

        if ((int)nodes.size() > capacity) {
            // remove leftmost node
            Node* left_most_node = left.next;
            remove(left_most_node);
            nodes.erase(left_most_node->key);
            delete left_most_node;
        }
    }
};

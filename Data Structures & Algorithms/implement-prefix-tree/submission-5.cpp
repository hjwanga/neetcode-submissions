class PrefixTree {
    struct Node {
        Node() {
            
        }
        Node* children[26] = {};
        bool is_word = false;
    };

    Node root;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Node* curr = &root;
        for (char c : word) {
            if (curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        // exact
        Node* curr = &root;
        for (char c : word) {
            if (curr->children[c-'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        // has
        Node* curr = &root;
        for (char c : prefix) {
            if (curr->children[c-'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return true;
    }
};

//   cat 
//   cate
//   dog

//    c    d
//    a    o
//    t.   g.
//    e.   
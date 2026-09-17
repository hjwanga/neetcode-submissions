class WordDictionary {
    struct Node {
        Node() = default;
        Node* children[26] = {};
        bool is_word = false;
    };
    Node root;

    bool dfs(const string& word, Node* curr, int start) {
        int n = word.size();
        for (int i = start; i < n; ++i) {
            char c = word[i];
            if (c == '.') {
                for (Node* child : curr->children) {
                    if (child && dfs(word, child, i+1)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (curr->children[c-'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c-'a'];
            }
        }
        return curr->is_word;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* curr = &root;
        for (const char& c : word) {
            if (curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        Node* curr = &root;
        return dfs(word, curr, 0);
    }
};

// insert: abc abcd
// a**

// bay
// cad
// bbb

// b*b


//      b     c
//    a   b   a
//    y   b   d
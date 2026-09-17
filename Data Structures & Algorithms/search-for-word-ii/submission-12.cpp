class Solution {
    struct Node {
        Node() = default;
        ~Node() {
            for (Node* child : children) {
                delete child;
            }
        }
        Node* children[26] = {};
        int children_count = 0;
        const string* word = nullptr;
    };
    Node root;

    void insert_word(const string& word) {
        Node* curr = &root;
        for (char c : word) {
            if (curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node();
                curr->children_count++;
            }
            curr = curr->children[c-'a'];
        }
        curr->word = &word;
    }

    void dfs(const vector<vector<char>>& board, int r, int c, Node* curr, vector<vector<bool>>& visited, vector<string>& result) {
        static constexpr int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = board.size();
        int n = board[0].size();

        if (!curr->children[board[r][c]-'a']) {
            return;
        }

        if (visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        Node* prev = curr;
        curr = curr->children[board[r][c]-'a'];
        if (curr->word) {
            result.push_back(*curr->word);
            // prevent duplicate: e.g., ["a","a"] a -> a. a <- a. push "aa" twice into result
            curr->word = nullptr;
        }
        for (const auto& dir : dirs) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
                continue;
            }
            dfs(board, new_r, new_c, curr, visited, result);
        }
        // pruning: e.g., ["a","a","a","a","a"] word = "aa"
        if (curr->children_count == 0) {
            prev->children[board[r][c]-'a'] = nullptr;
            prev->children_count--;
            delete curr;
        }
        visited[r][c] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. insert words to trie
        for (const string& word : words) {
            insert_word(word);
        }

        // 2. dfs board
        vector<string> result;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dfs(board, r, c, &root, visited, result);
            }
        }
        return result;
    }
};

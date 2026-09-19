class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // constraint1: endWord must in list
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) {
            return 0;
        }

        // 1. do bfs to get min distance from beginWord to endWord
        queue<string> que;
        que.push(beginWord);
        words.erase(beginWord);

        int result = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                string node = que.front();
                if (node == endWord) {
                    return result;
                }
                que.pop();

                // 2. try 'a'-'z' at every position. using backtrack
                int len = node.size();
                for (int j = 0; j < len; ++j) {
                    char backup = node[j];
                    for (int k = 0; k < 26; ++k) {
                        char c = 'a'+k;
                        if (c == backup) {
                            continue;
                        }
                        node[j] = c;
                        // use erase to represent visited
                        if (words.count(node)) {
                            que.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = backup;
                }
            }
            ++result;
        }
        return 0;
    }
};


// 1. end must in list

// begin: cat
// end: sag
// list: [bat, bag, sag, dag, dot]
//  cat ->  bat - bag - sag | dot
//                 \    /
//                   dag

// begin: cat
// end: sag
// list: [bat, bag, sat, dag, dot]
//  cat -> bat - bag - dag . dot
//          |
//         sat




struct TrieNode {
    unordered_map<char, TrieNode*> next;
    bool flag;
};

class Trie {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next.count(word[i]) <= 0) {
                node->next[word[i]] = new TrieNode();
            }
            
            node = node->next[word[i]];
        }
        
        node->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next.count(word[i]) <= 0 ) {
                return false;
            }
            
            node = node->next[word[i]];
        }
        
        return node->flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (node->next.count(prefix[i]) <= 0 ) {
                return false;
            }
            
            node = node->next[prefix[i]];
        }
        
        return true;
    }
};

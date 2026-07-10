class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word = 0;
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();

public:
    WordDictionary() {}

    void addWord(string word) {
        auto cur = root;
        for (auto& c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->is_word = 1;
    }

    bool search(string& word, TrieNode* node, int k) {
        if (!node)
            return 0;

        if (k == word.size()) {
            return node->is_word;
        }

        if (word[k] == '.') {
            for (auto& [c, child] : node->children) {
                if (search(word, child, k + 1)) {
                    return 1;
                }
            }
            return 0;
        }

        return node->children.count(word[k])
                   ? search(word, node->children[word[k]], k + 1)
                   : 0;
    }

    bool search(string word) { return search(word, root, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
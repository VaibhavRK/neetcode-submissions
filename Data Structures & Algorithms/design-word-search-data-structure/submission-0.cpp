class Node {
public:
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
               node->put(ch, new Node());
            }
            node = node->links[ch-'a'];
        }
        node->setEnd();
    }

    bool checkWord(Node* node, string word, int i){
        if (node == nullptr) return false;
        
        // Base case: reached the end of the word
        if (i == word.length()) {
            return node->flag;
        }

        char ch = word[i];
        if (ch == '.') {
            // Try all 26 possible branches
            for (int j = 0; j < 26; j++) {
                if (node->links[j] != nullptr && checkWord(node->links[j], word, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->containsKey(ch)) return false;
            return checkWord(node->links[ch - 'a'], word, i + 1);
        }
    }
    
    bool search(string word) {
        return checkWord(root, word, 0);
    }
};
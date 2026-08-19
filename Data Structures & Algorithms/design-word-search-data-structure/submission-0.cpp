
struct Node{

    Node* links[26] = {};

    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] == nullptr ? false : true;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    void incrEndsWith(){
        cntEndsWith++;
    }

    void decrEndsWith(){
        cntEndsWith--;
    }

    void incrPrefix(){
        cntPrefix++;
    }

    void decrPrefix(){
        cntPrefix--;
    }

    void deleteEnd(){
        cntEndsWith--;
    }

    int getEndsWith(){
        return cntEndsWith;
    }

    int getPrefix(){
        return cntPrefix;
    }


    ~Node(){
        for(int i = 0; i < 26; i++){
            if(links[i] != nullptr) delete links[i];
        }
    }


};

class WordDictionary {

    Node* root;

public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(const string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node);
            }
            node = node->get(word[i]);
            node->incrPrefix();
        }
        node->incrEndsWith();
    }

    bool searchHelper(int idx, const string& word, Node* node){
        if(node == nullptr) return false;
        if(idx == word.size()) return node->getEndsWith() > 0;

        char ch = word[idx];
        if(ch == '.') {
            for(int c = 0; c < 26; c++){
                if(node->get(c + 'a') != nullptr && searchHelper(idx + 1, word, node->get(c + 'a'))){
                    return true;
                }
            }
            return false;
        }
        else{
            if(!node->containsKey(ch)) return false;
            return searchHelper(idx + 1, word, node->get(ch));
        }


    }
    
    bool search(const string &word) {
        Node* node = root;
        return searchHelper(0, word, node);
    }

    ~WordDictionary(){
        delete root;
    }
};

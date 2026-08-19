
struct Node {

    Node* links[26] = {};

    int cntEndsWith = 0;
    int cntPrefix = 0;


    bool containsKey(const char& ch){
        return links[ch - 'a'] != nullptr;
    }

    Node* get(const char& ch){
        return links[ch - 'a'];
    }

    void put(const char& ch, Node* node){
        links[ch - 'a'] = node;
    }

    void incrEndsWith(){
        cntEndsWith++;
    }

    void incrPrefix(){
        cntPrefix++;
    }

    void decrEndsWith(){
        cntEndsWith--;
    }

    void decrPrefix(){
        cntPrefix--;
    }

    void deleteEnd(){
        cntEndsWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEndsWith(){
        return cntEndsWith;
    }

    int getPrefix(){
        return cntPrefix;
    }

    ~Node(){
        for(int i = 0; i < 26; i++){
            if(links[i] != nullptr){
                delete links[i];
            }
        }
    }

};

class PrefixTree {

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(const string& word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
            node->incrPrefix();
        }
        node->incrEndsWith();
        cout << node->getEndsWith() << endl;
    }
    
    bool search(const string &word) {
        
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else return false;
        }

        return node->getEndsWith() ? true : false;

    }
    
    bool startsWith(string prefix) {
        
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(node->containsKey(prefix[i])){
                node = node->get(prefix[i]);
            }
            else return false;
        }

        return node->getPrefix() ? true : false;

    }

    ~PrefixTree(){
        delete root;
    }
};

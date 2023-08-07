class Trie {
struct Node{
    Node *links[26];
    bool flag = false;

    bool containChar(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putChar(char ch,Node *node){
        links[ch-'a']=node;
    }

    Node* getChar(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool getEnd(){
        return flag;
    }

};
private: Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containChar(word[i])){
                temp->putChar(word[i],new Node());
            }
            temp = temp->getChar(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containChar(word[i])){
                return false;
            }
            temp = temp->getChar(word[i]);
        }
        if(!temp->getEnd()){
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->containChar(prefix[i])){
                return false;
            }
            temp = temp->getChar(prefix[i]);
        }
        return true;
    }
};
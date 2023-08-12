#include<bits/stdc++.h>
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
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};
class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    void insert(std::string word){
        Node *temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containChar(word[i])){
                temp->putChar(word[i],new Node());
            }
            temp = temp->getChar(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(std::string word){
        Node *temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containChar(word[i])){
                return false;
            }
            temp = temp->getChar(word[i]);
        }
        if(!temp->isEnd()){
            return false;
        }
        return true;
    }
    
    bool substr(std::string word){
        Node *temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containChar(word[i])){
                return false;
            }
            temp = temp->getChar(word[i]);
        }
        return true;
    }
};
int main(){
    Trie obj;
    std::string sArr[] = {"apple","appd","bad","badac"};
    int size = sizeof(sArr)/sizeof(sArr[0]);
    for(int i=0;i<size;i++){
        obj.insert(sArr[i]);
    }
    
    for(int i=0;i<size;i++){
        if(i%2==0){
            std::cout<<obj.search(sArr[i])<<"\n";
        }   
    }
    
    std::cout<<obj.substr("app")<<"\n";
}
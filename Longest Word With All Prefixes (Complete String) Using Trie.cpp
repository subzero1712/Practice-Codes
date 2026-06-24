#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setFlag(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
    private: Node* root;
    public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setFlag();
    }

    bool checkIfPrefixExist(string word){
        Node* node=root;
        bool fl=true;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false) return false;
            }
            else return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto& it:a){
        trie.insert(it);
    }
    string longest="";
    for(auto &it:a){
        if(trie.checkIfPrefixExist(it)){
            if(it.length()>longest.length()){
                longest=it;
            }
            else if(it.length()==longest.length() && it<longest){
                longest=it;
            }
        }
    }
    if(longest=="") return "None";
    return longest;
}

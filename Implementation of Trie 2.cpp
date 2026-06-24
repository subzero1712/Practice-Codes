#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int cntEndWith=0;
    int cntPrefix=0;

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void incEnd(){
        cntEndWith++;
    }
    void incPrefix(){
        cntPrefix++;
    }
    void redEnd(){
        cntEndWith--;
    }
    void redPre(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPref(){
        return cntPrefix;
    }
};
class Trie{
    private: Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->incPrefix();
        }
        node->incEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getPref();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
               node=node->get(word[i]);
               node->redPre(); 
            }else{
                return;
            }
        }
        node->redEnd();
    }
};

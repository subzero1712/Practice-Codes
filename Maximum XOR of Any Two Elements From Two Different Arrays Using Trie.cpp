#include<bits/stdc++.h>
struct Node{
    Node* links[2];
    bool containsKey(int num){
        return (links[num]!=NULL);
    }
    Node* get(int num){
        return links[num];
    }
    void put(int num, Node* node){
        links[num]=node;
    }
};

class Trie{
    private: Node* root;
    public: Trie(){
        root=new Node();
    }
    public:
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }
    public:
    int getMax(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxi;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(auto &it:arr1){
        trie.insert(it);
    }
    int maxi=0;
    for(auto &it:arr2){
        maxi=max(maxi, trie.getMax(it));
    }
    return maxi;
}

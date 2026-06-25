#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];

    Node(){
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int num){
        return (links[num] != NULL);
    }

    Node* get(int num){
        return links[num];
    }

    void put(int num, Node* node){
        links[num] = node;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxi = 0;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(node->containsKey(1 - bit)){
                maxi |= (1 << i);
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int,int>>> oq;

        for(int i = 0; i < queries.size(); i++){
            oq.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oq.begin(), oq.end());

        vector<int> ans(queries.size());

        int ind = 0;
        int n = nums.size();

        Trie trie;

        for(int i = 0; i < oq.size(); i++){

            int ai = oq[i].first;
            int xi = oq[i].second.first;
            int Qind = oq[i].second.second;

            while(ind < n && nums[ind] <= ai){
                trie.insert(nums[ind]);
                ind++;
            }

            if(ind == 0)
                ans[Qind] = -1;
            else
                ans[Qind] = trie.getMax(xi);
        }

        return ans;
    }
};

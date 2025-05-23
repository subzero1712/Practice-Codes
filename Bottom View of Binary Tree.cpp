#include "bits/stdc++.h"
vector<int> bottomView(TreeNode<int> * root){
     vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mpp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode<int>* node=it.first;
        int line=it.second;
        mpp[line]=node->data;
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1}); 
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

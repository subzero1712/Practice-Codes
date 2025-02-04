#include <bits/stdc++.h> 
bool valid(BinaryTreeNode<int>* root, long long mini, long long maxi){
    if(root==NULL) return true;
    if(root->data<=mini || root->data>=maxi){
        return false;
    }

    return valid(root->left,mini,root->data) && valid(root->right,root->data,maxi);
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return valid(root,LLONG_MIN,LLONG_MAX);
}

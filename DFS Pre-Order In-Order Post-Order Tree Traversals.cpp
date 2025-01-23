void inorder(vector<int>&ino ,TreeNode *root){
    if(root==NULL){
        return;
    }
    inorder(ino,root->left);
    ino.push_back(root->data);
    inorder(ino,root->right);
}

void preorder(vector<int>&pre, TreeNode *root){
    if(root==NULL){
        return;
    }
    pre.push_back(root->data);
    preorder(pre,root->left);
    preorder(pre,root->right);
}

void postorder(vector<int>&pos, TreeNode *root){
    if(root==NULL){
        return;
    }
    postorder(pos,root->left);
    postorder(pos,root->right);
    pos.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> ino,pre,pos;
    inorder(ino,root);
    preorder(pre,root);
    postorder(pos,root);
    vector<vector<int>>ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}

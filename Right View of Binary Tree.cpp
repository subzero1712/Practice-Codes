class Solution {
public:
    void func1(TreeNode* root, int level,vector<int> &ds){
        if(root==NULL){
            return;
        }
        if(level==ds.size()){
            ds.push_back(root->val);
        }
        func1(root->right,level+1,ds);
        func1(root->left,level+1,ds);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        func1(root,0,ds);
        return ds;
    }
};

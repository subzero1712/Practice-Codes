class Solution {
public:
    void inorder(vector<int> &arr, TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(arr,root->left);
        arr.push_back(root->val);
        inorder(arr,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(ans,root);
        return ans;
    }
};

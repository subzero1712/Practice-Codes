class Solution {
public:
    void preorder(vector<int> &arr,TreeNode* root){
        if(root==NULL){
            return;
        }
        arr.push_back(root->val);
        preorder(arr,root->left);
        preorder(arr,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(arr,root);
        return arr;
    }
};

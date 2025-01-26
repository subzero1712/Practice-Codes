class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(dfs(root)==-1){
            return false;
        }
        return true;
    }
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int l=dfs(root->left);
        if(l==-1) return -1;
        int r=dfs(root->right);
        if(r==-1) return -1;

        if(abs(l-r)>1) return -1;
        return max(l,r)+1;
    }
};

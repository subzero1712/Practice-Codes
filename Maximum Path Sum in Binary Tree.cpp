class Solution {
public:
    int maxDepth(TreeNode* root,int& maxi) {
        if(root==NULL) return 0;
        //if returning negative sum then return 0 instead as negative will not let us have max sum
        int l=max(0,maxDepth(root->left,maxi));
        int r=max(0,maxDepth(root->right,maxi));
        maxi=max(maxi,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int path=INT_MIN;
        maxDepth(root,path);
        return path;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Recursive Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        TreeNode* curr=root;
        if(p->val>curr->val && q->val>curr->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(p->val<curr->val && q->val<curr->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};

//Non Recursive Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        TreeNode* curr=root;
        TreeNode* ans;
        while(curr!=NULL){
            if(curr->val<p->val && curr->val<q->val){
                curr=curr->right;
            }
            else if(curr->val>p->val && curr->val>q->val){
                curr=curr->left;
            }
            else{
                ans=curr;
                break;
            }
        }
        return ans;
    }
};

/**  
 * Definition for a binary tree node.  
 * struct TreeNode {  
 *     int val;  
 *     TreeNode *left;  
 *     TreeNode *right;  
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}  
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  
 * };  
 */  
class Solution {  
public:  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {  
        map<int, int> mpp;  
        for (int i = 0; i < inorder.size(); i++) {  
            mpp[inorder[i]] = i;  
        }  
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);  
    }  

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,  
                    vector<int>& postorder, int postStart, int postEnd,  
                    map<int, int>& mpp) {  
        if (inStart > inEnd || postStart > postEnd) return NULL;  // Base case

        TreeNode* root = new TreeNode(postorder[postEnd]);  // Correct root selection  
        int inRoot = mpp[root->val];  // Index of root in inorder traversal  
        int numsLeft = inRoot - inStart;  // Nodes in left subtree  

        // Recursively build left and right subtrees  
        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, mpp);  
        root->right = build(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, mpp);  

        return root;  
    }  
};  

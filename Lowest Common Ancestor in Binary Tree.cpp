//Brute Approach
class Solution {
public:
    bool getPath(TreeNode* root, vector<TreeNode*>& arr, TreeNode* x) {
        if (root == NULL) {
            return false;
        }
        arr.push_back(root);
        if (root == x) {
            return true;
        }
        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }
        arr.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1, arr2; 
        if (root == NULL) {
            return NULL;
        }
        getPath(root, arr1, p);
        getPath(root, arr2, q);
        
        TreeNode* ans = NULL;
        int n = min(arr1.size(), arr2.size()); 
        for (int i = 0; i < n; i++) {
            if (arr1[i] == arr2[i]) {
                ans = arr1[i];
            } else {
                break;
            }
        }
        return ans;
    }
};

//Optimal Approach
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
         
         TreeNode* left=lowestCommonAncestor(root->left,p,q);
         TreeNode* right=lowestCommonAncestor(root->right,p,q);

         if(left==NULL) return right;
         else if(right==NULL) return left;
         else return root;
    }
};

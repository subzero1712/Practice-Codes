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
        vector<TreeNode*> arr1, arr2; // Correct initialization
        if (root == NULL) {
            return NULL;
        }
        getPath(root, arr1, p);
        getPath(root, arr2, q);
        
        TreeNode* ans = NULL;
        int n = min(arr1.size(), arr2.size()); // Ensure bounds are respected
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

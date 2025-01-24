//Using 2 Stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL) st1.push(root->left);
            if(root->right!=NULL) st1.push(root->right);
        }
        while(st2.empty()==false){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};

//Using 1 Stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* lastVisited = NULL;

        while (root != NULL || !st.empty()) {
            if (root != NULL) {
                st.push(root);
                root = root->left; 
            } else {
                TreeNode* node = st.top();
                if (node->right != NULL && lastVisited != node->right) {
                    root = node->right; 
                } else {
                    postorder.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return postorder;
    }
};

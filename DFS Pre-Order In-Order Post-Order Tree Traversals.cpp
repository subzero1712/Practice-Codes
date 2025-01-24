void inorder(vector<int>&ino ,TreeNode *root){
    if(root==NULL){
        return;
    }
    inorder(ino,root->left);
    ino.push_back(root->data);
    inorder(ino,root->right);
}

void preorder(vector<int>&pre, TreeNode *root){
    if(root==NULL){
        return;
    }
    pre.push_back(root->data);
    preorder(pre,root->left);
    preorder(pre,root->right);
}

void postorder(vector<int>&pos, TreeNode *root){
    if(root==NULL){
        return;
    }
    postorder(pos,root->left);
    postorder(pos,root->right);
    pos.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> ino,pre,pos;
    inorder(ino,root);
    preorder(pre,root);
    postorder(pos,root);
    vector<vector<int>>ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}
//all at once using one stack
class Solution {
public:
    vector<int> postOrder(Node* root) {
        // Use a stack of pairs to track the node and its state
        stack<pair<Node*, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;

        if (root == NULL) return post; // Return empty vector if the root is NULL

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            // Preorder: State 1
            if (it.second == 1) {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }
            // Inorder: State 2
            else if (it.second == 2) {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }
            // Postorder: State 3
            else {
                post.push_back(it.first->val);
            }
        }

        return post; // Return the postorder traversal
    }
};

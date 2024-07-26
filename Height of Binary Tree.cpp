class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node==NULL){
            return 0;
        }
        
        int right = height(node->right);
        int left = height(node->left);
        
        int ans = max(left, right)+1;
        return ans;
    }
};

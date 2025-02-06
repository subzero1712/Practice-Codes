/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class nodeValue {
public:
    int maxValue, minValue, maxSize;
    
    nodeValue(int minValue, int maxValue, int maxSize) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};

nodeValue largestSubtree(TreeNode* root) {
    if (!root) {
        return nodeValue(INT_MAX, INT_MIN, 0);
    }

    auto left = largestSubtree(root->left);
    auto right = largestSubtree(root->right);

    if (left.maxValue < root->data && right.minValue > root->data) {
        return nodeValue(
            min(root->data, left.minValue), 
            max(root->data, right.maxValue), 
            left.maxSize + right.maxSize + 1
        );
    }

    return nodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode *root) {
    return largestSubtree(root).maxSize;
}

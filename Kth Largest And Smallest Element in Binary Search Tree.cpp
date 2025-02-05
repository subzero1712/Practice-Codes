//Kth Smallest Element
class Solution {
public:
    void inorder(TreeNode* root, int k, int &cnt, int& kSmallest){
        if(root==NULL || cnt>=k){
            return;
        }
        inorder(root->left,k,cnt,kSmallest);

        cnt++;
        if(cnt==k){
            kSmallest=root->val;
            return;
        }

        inorder(root->right,k,cnt,kSmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest=INT_MIN;
        int cnt=0;
        inorder(root,k,cnt,kSmallest);
        return kSmallest;
    }
};

//Kth Largest Element
void reverseInorder(TreeNode<int>* root, int &cnt, int k, int& kLargest){
    if(root==NULL || cnt>=k){
        return;
    }

    reverseInorder(root->right,cnt,k,kLargest);

    cnt++;
    if(cnt==k){
        kLargest=root->data;
        return;
    }

    reverseInorder(root->left,cnt,k,kLargest);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int kLargest=-1;
    int cnt=0;
    reverseInorder(root,cnt,k,kLargest);
    return kLargest;
}

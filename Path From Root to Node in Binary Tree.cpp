#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool path(TreeNode<int>* root, int x, vector<int>& arr){
	if(root==NULL) return false;
	arr.push_back(root->data);
	if(root->data==x) return true;
	if(path(root->left,x,arr)||path(root->right,x,arr)) return true;
	arr.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	path(root,x,ans);
	return ans;
}

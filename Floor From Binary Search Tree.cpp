int Floor(BinaryTreeNode<int> *node, int input)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	int floor=INT_MAX;
	while(node!=NULL){
		if(node->data==input){
			floor=input;
			return floor;
		}
		else if(input<node->data){
			node=node->left;
		}
		else{
			floor=node->data;
			node=node->right;
		}
	}
	return floor;
}

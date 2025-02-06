#include <bits/stdc++.h> 

int successor(binaryTreeNode* root, int key){  
	int succ = -1;
	while(root != NULL){
		if(key >= root->data){  
			root = root->right;
		} else {
			succ = root->data;  
			root = root->left;
		}
	}
	return succ;
}

int predecessor(binaryTreeNode* root, int key){  
	int pred = -1;
	while(root != NULL){
		if(key > root->data){  
			pred = root->data; 
			root = root->right;
		} else {
			root = root->left;
		}
	}
	return pred;
}

vector<int> findPreSuc(binaryTreeNode *root, int key) {
	vector<int> ans;
	int p = predecessor(root, key);  
	int s = successor(root, key);    
	ans.push_back(p); 
	ans.push_back(s); 
	return ans;
}

//Minimum element
#include<bits/stdc++.h>
int minVal(Node* root) {
    if (root == NULL) return -1; // Handle empty tree case
    while (root->left != NULL) { // Traverse left until the last node
        root = root->left;
    }
    return root->data; // Return the leftmost node value
}

//Maximum element
int maxVal(Node* root) {
    if (root == NULL) return -1; // Handle empty tree case
    while (root->right != NULL) { // Traverse right until the last node
        root = root->right;
    }
    return root->data; // Return the rightmost node value
}


#include<bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;  
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long minn = q.front().second; 
            long long first, last;

            for (int i = 0; i < size; i++) {
                long long curr_id = q.front().second - minn;  
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curr_id;
                if (i == size - 1) last = curr_id;

                if (node->left) {
                    q.push({node->left, curr_id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, curr_id * 2 + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};

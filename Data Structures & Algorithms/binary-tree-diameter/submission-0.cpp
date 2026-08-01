/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    using t = TreeNode;

    int dfs(t* node, int& maxdiameter){
        if(node == nullptr) return 0;

        int left = 0, right = 0;

        if(node->left != nullptr){
            left = dfs(node->left, maxdiameter);
        }
        if(node->right != nullptr){
            right = dfs(node->right, maxdiameter);
        }

        int diameter = left + right;

        maxdiameter = max(maxdiameter, diameter);

        return max(left, right) + 1;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int mx = INT_MIN;
        dfs(root, mx);
        return mx;
    }
};

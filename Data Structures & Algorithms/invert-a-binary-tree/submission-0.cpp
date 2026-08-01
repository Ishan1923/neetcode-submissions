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

    TreeNode* dfs(TreeNode* node){
        if(node == nullptr) return nullptr;

        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        if(node->left != nullptr){
            dfs(node->left);
            left = node->left;
        }
        if(node->right != nullptr){
            dfs(node->right);
            right = node->right;
        }
        
        node->left = right;
        node->right = left;

        return node;
    }

    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};

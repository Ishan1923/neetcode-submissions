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

    bool inorder(TreeNode* node, TreeNode*& prev){
        if(node == nullptr) return true;

        if(!inorder(node->left, prev)) return false;

        if(prev != nullptr && prev->val >= node->val) return false;

        prev = node;

        if(!inorder(node->right, prev)) return false;

        return true;

    }


    bool isValidBST(TreeNode* root) {

        if(root == nullptr) return true;

        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
};

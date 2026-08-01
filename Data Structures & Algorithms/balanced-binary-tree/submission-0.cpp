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

    int dfs(t* node, bool& isBalanced){
        if(node == nullptr) return 0;

        if(!isBalanced) return 0;

        int left = dfs(node->left, isBalanced);
        int right = dfs(node->right, isBalanced);

        if(abs(left - right) > 1){
            isBalanced = false;
            return 0;
        }

        return max(left, right) + 1;


    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool isBalanced = true;
        dfs(root, isBalanced);
        return isBalanced;
    }
};

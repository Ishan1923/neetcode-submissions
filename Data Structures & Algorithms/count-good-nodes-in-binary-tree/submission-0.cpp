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

    void dfs(TreeNode* node, int mx, int& good_nodes){
        if(node == nullptr) return;

        int temp = mx;

        if(mx <= node->val){
            mx = node->val;
            good_nodes++;
        }

        dfs(node->left, mx, good_nodes);
        dfs(node->right, mx, good_nodes);

        mx = temp;

    }


    int goodNodes(TreeNode* root) {

        int mx = INT_MIN;

        int good_nodes = 0;

        dfs(root, mx, good_nodes);

        return good_nodes;
        
    }
};

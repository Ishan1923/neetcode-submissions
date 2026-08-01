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

    bool check(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr)  return false;
        if(node1->val != node2->val) return false;

        return check(node1->left, node2->left) && check(node1->right, node2->right);
    }

    void dfs(TreeNode* node, TreeNode* subRoot, bool& ans){
        if(node == nullptr) return;

        if(check(node, subRoot) == true){
            ans = true;
            return;
        }

        dfs(node->left, subRoot, ans);

        dfs(node->right, subRoot, ans);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;

        dfs(root, subRoot, ans);

        return ans;

    }
};

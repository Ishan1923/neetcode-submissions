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

    void inorder(TreeNode* node, const int& k, vector<int>& buffer){
        if(node == nullptr) return;

        inorder(node->left, k, buffer);

        if(buffer.size() < k){
            buffer.push_back(node->val);
        }

        inorder(node->right, k, buffer);

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> buffer;
        inorder(root, k, buffer);
        return buffer.back();
    }
};

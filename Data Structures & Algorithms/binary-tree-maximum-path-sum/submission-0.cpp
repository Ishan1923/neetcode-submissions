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

    pair<int, int> dfs(TreeNode* node){
        int nodeVal = node->val;
        auto fromLeft = node->left ? dfs(node->left) : pair<int, int>{-1e9, -1e9};
        auto fromRight = node->right ? dfs(node->right) : pair<int, int>{-1e9, -1e9};

        int sum1 = fromLeft.second + nodeVal;
        int sum2 = fromRight.second + nodeVal;
        int sum3 = sum1  + sum2 - nodeVal;


        return {max({sum1, sum2, sum3, nodeVal, fromLeft.first, fromLeft.second, fromRight.first, fromRight.second}), max({nodeVal, sum1, sum2})};
    }

    int maxPathSum(TreeNode* root) {

        auto ans = dfs(root);

        return max(ans.first, ans.second);

    }
};

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

    TreeNode* dfs(unordered_map<int, int>& mp, const vector<int>& preorder, const vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd){

        if(inStart > inEnd || preStart > preEnd) return nullptr;

        TreeNode* root = new TreeNode();

        root->val = preorder[preStart];

        int inIdxRoot = mp[root->val];

        int numsInLeftSubtree = inIdxRoot - inStart; 
        int n = preorder.size();

        root->left = dfs(mp, preorder, inorder, inStart, inIdxRoot - 1, preStart + 1, preStart + numsInLeftSubtree);

        root->right = dfs(mp, preorder, inorder, inIdxRoot + 1, inEnd, preStart + numsInLeftSubtree + 1, preEnd);



        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        int n = preorder.size();

        return dfs(mp, preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

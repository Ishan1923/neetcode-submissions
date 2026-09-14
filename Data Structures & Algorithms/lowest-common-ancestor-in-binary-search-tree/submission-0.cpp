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

    // TreeNode* find(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent){
    //     if(node == parent[node]) return parent[node];
    //     return parent[node] = find(parent[node], parent);
    // }

    // void unite(TreeNode* node1, TreeNode* node2, unordered_map<TreeNode*, TreeNode*>& parent){
    //     TreeNode* parent_node1 = find(node1, parent);
    //     TreeNode* parent_node2 = find(node2, parent);

    //     if()

    // }

    void dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& lca){

        if(node->val > p->val && node->val > q->val){
            if(node->left) dfs(node->left, p, q, lca);
            // else{

            // }
            return;
        }
        else if(node->val < p->val && node->val < q->val){
            if(node->right) dfs(node->right, p, q, lca);
            // else{

            // }
            return;
        }
        // else if( (node->val <= p->val && node->val >= q->val) || (node->val >= p->val && node->val <= q->val) ) 
        // {
            
        // }

        lca = node;
        return;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = new TreeNode(-102);
        dfs(root, p, q, lca);
        return lca;
    }
};

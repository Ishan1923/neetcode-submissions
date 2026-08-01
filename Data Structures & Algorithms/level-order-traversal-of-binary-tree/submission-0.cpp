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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();

            vector<int> temp;
            
            while(size){
                size--;
                auto top = q.front();
                temp.push_back(q.front()->val);
                q.pop();
                if(top->left != nullptr) q.push(top->left);
                if(top->right != nullptr) q.push(top->right);
            }
            ans.push_back(temp);
 
        }
        

        return ans;
    }
};

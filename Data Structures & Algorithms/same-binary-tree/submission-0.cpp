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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false;

        queue<t*> q1;
        queue<t*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            auto top1 = q1.front();
            auto top2 = q2.front();

            q1.pop();
            q2.pop();

            if(top1 == nullptr && top2 == nullptr) continue;
            if(top1 == nullptr || top2 == nullptr) return false;
            if(top1->val != top2->val) return false;

            q1.push(top1->left);
            q1.push(top1->right);
            q2.push(top2->left);
            q2.push(top2->right);

        }


        return true;


        
    }
};

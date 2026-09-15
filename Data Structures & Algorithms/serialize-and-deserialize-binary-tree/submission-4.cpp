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

class Codec {

    void tree2str(TreeNode* root, string& s){
        
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();

                s += (node != nullptr) ? to_string(node->val) + "," : "#,";

                if(node == nullptr) continue;

                q.push(node->left);
                q.push(node->right);

            }
        }

    }

    TreeNode* str2tree(vector<string>& s){
        if(s.empty() || s[0] == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(s[0]));

        queue<TreeNode*> q;

        q.push(root);

        int idx = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(idx < s.size() && s[idx] != "#"){
                node->left = new TreeNode(stoi(s[idx]));
                q.push(node->left);
            }
            idx++;
            if(idx < s.size() && s[idx] != "#"){
                node->right = new TreeNode(stoi(s[idx]));
                q.push(node->right);
            }
            idx++;
        }

        return root;
    }


public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        tree2str(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> processed_data;

        string num = "";
        bool neg = false;

        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                if(neg) num = "-" + num;
                processed_data.push_back(num);
                num = "";
                neg = false;
                continue;
            }
            if(data[i] == '-'){
                neg = true;
                continue;
            }

            num = num + data[i];            

        }

        for(int i = processed_data.size() - 1; i >= 0; i--){
            if(processed_data[i] != "#") break;
            processed_data.pop_back();
        }

        return str2tree(processed_data);
    }
};

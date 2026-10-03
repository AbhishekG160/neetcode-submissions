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
    void shelper(TreeNode* root, string& s){
        if(!root){
            s += "nullptr,";
            return;
        }
        s += to_string(root->val)+",";
        shelper(root->left, s);
        shelper(root->right, s);
        return;
    }
    TreeNode* Dhelper(stringstream& str){
        string s;
        if(!getline(str, s, ','))
            return nullptr;
        if(s == "nullptr")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = Dhelper(str);
        node->right = Dhelper(str);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        shelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str(data);
        return Dhelper(str);
    }
};

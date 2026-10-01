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
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if(l == -1 || r == -1)
            return -1;
        if(abs(l-r) > 1)
            return -1;
        return 1+(max(l, r));
    }
    bool isBalanced(TreeNode* root) {
        return (helper(root) == -1)?false:true;
    }
};

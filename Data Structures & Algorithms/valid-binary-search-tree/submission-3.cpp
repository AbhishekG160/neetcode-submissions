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
    bool helper(TreeNode* root, int minm, int maxm){
        if(!root)
            return true;
        if(root->val <= minm || root->val >= maxm)
            return false;
        return helper(root->left, minm, root->val) && helper(root->right, root->val, maxm);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return helper(root, -1e8, 1e8);
    }
};

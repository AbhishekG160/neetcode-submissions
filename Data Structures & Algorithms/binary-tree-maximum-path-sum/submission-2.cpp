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
    int maxm = INT_MIN;
    int helper(TreeNode* root){
        if(!root) 
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        // maxm = max(maxm, l+r);
        // return root->val+max(l,r);
        maxm = max(maxm, root->val+ max(0,l) + max(0,r));
        return root->val + max({0, l, r});
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxm;
    }
};

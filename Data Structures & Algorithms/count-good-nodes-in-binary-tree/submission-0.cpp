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
    int count = 0;
public:
    void helper(TreeNode* root, int maxm){
        if(!root)
            return;
        if(root->val >= maxm){
            count++;
            maxm = root->val;
        }
        helper(root->left, maxm);
        helper(root->right, maxm);
    }
    int goodNodes(TreeNode* root) {
        int maxm = -1e7;
        helper(root, maxm);
        return count;
    }
};

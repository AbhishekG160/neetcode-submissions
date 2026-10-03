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
    pair<int,int> helper(TreeNode* root){
        if(!root)
            return {0, 0};
        auto [lrob, lskip] = helper(root->left);
        auto [rrob, rskip] = helper(root->right);
        int currrob = lskip + rskip + root->val;
        int currskip = max(lskip, lrob) + max(rskip, rrob);
        return {currrob, currskip};
    }
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        auto [rootrob, rootskip] = helper(root);
        return max(rootrob, rootskip);
    }
};
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
    bool help2(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        if(r1->val != r2->val)
            return false;
        return help2(r1->left, r2->left) && help2(r1->right, r2->right);
    }
    bool helper(TreeNode* root, TreeNode* r){
        if(!root)
            return false;
        if(root->val == r->val)
            if(help2(root, r))
                return true;
        bool left = helper(root->left, r);
        bool right = helper(root->right, r);
        if(left || right)
            return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot);
    }
};

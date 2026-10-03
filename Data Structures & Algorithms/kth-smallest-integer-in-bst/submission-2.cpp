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
    // int count;
    // int val;
public:
    void helper(TreeNode* root, vector<int>& temp){
        if(!root)
            return;
        helper(root->left, temp);
        temp[0]--;
        if(temp[0] == 0){
            temp[1] = root->val;
            return;
        }
        helper(root->right, temp);
    }
    int kthSmallest(TreeNode* root, int k) {
        // count = k;
        // helper(root);
        // return val;
        vector<int> temp(2);
        temp[0] = k;
        helper(root, temp);
        return temp[1];
    }
};

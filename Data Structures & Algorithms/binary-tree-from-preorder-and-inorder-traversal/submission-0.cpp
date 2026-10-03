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
private:
    unordered_map<int, int> inordermap;
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr){
        if(prel>prer || inl>inr)
            return nullptr;
        int val = preorder[prel];
        int idxinorder = inordermap[val];
        int numsonleft = idxinorder - inl;
        TreeNode* root = new TreeNode(val);
        root->left = helper(preorder, inorder, prel+1, prel+numsonleft, inl, idxinorder-1);
        root->right = helper(preorder, inorder, prel+numsonleft+1, prer, idxinorder+1, inr);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i=0; i<n; ++i) 
            inordermap[inorder[i]] = i;
        TreeNode* root = helper(preorder, inorder, 0, n-1, 0, n-1);
        return root;
    }
};

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
    // TreeNode* helper(TreeNode* root, int key){
    //     if(!root)
    //         return nullptr;
    //     if(root->val < key)
    //         root->right = helper(root->right, key);
    //     else if(root->val > key)
    //         root->left = helper(root->left, key);
    //     else {
    //         if(!root->left && !root->right)
    //             return nullptr;
    //         if(!root->left)
    //             return root->right;
    //         if(!root->right)
    //             return root->left;

    //         // need inorder succesor of root
    //         TreeNode* l = root->left;
    //         TreeNode* r = root->right;
    //         // max in the left subtree
    //         TreeNode* maxl = l;
    //         while(maxl->right) maxl = maxl->right;
    //         maxl->right = r;
    //         delete root;
    //         return l;
    //     }
    //     return root;
    // }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if(!root->left && !root->right)
                return nullptr;
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;

            // need inorder succesor of root
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            // max in the left subtree
            TreeNode* maxl = l;
            while(maxl->right) maxl = maxl->right;
            maxl->right = r;
            delete root;
            return l;
        }
        return root;
    }
};
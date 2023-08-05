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

/*
    Problem:
      Given the root of a binary tree, invert the tree, and return its root.

*/
    TreeNode* invertTree(TreeNode* root) {
        
        //make sure root is not null
        if(!root){
            return nullptr;
        }

        //swap the left and right subtrees
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;

        //perform same swapping on all other subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};

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
        Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. 
        Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). 
        It can be proven that there is a unique answer. Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
  
  */
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       
        if(!root) return NULL;
        if(root->val < low) return trimBST(root->right, low, high); // if current node is too low, replace the parent nodes child with the right subtree of the current node

        if(root->val > high) return trimBST(root->left, low, high); // if the current node is too high, replace the parents nodes child with the left subtree of the current node

        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

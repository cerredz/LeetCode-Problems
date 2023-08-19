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
      Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
      A leaf is a node with no children.

    Approach:
        1. Instead of having another function and keep track of a running run, we can just subtract
            from the target sum.
        2. As we traverse through the tree we will be subtracting the current root's value from 
            targetSum. By Doing this if we ever run into a leaf node and the targetSum is 0, this
            means that there has to be a path that adds up to target sum.
*/
    bool targetFound = false;
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(!root){
            return false;
        }

        if(targetSum - root->val == 0 && !root->left && !root->right) {
             //if even true once, we want to return it at the end, so save in a global variable
            targetFound = true;
        }

        //travere through the tree, subtracting the values of the current root
        if(root->left) {
            hasPathSum(root->left, targetSum - root->val);
        }

        if(root->right){
            hasPathSum(root->right, targetSum - root->val);
        }

        return targetFound;
    }
};

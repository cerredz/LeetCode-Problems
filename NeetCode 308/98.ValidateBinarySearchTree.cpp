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
          Given the root of a binary tree, determine if it is a valid binary search tree (BST). A valid BST is defined as follows:
          The left subtree of a node contains only nodes with keys less than the node's key. The right subtree of a node contains only nodes with keys greater than the node's key.
          Both the left and right subtrees must also be binary search trees.

    */
    // helper function, we will make sure that every node is in between the neccessary left and right bounds
    // and if it is not we will return false. In order for this to work we must update the bounds
    // when we are traversing the tree accordingly
    bool dfs(TreeNode* root, long left, long right) {

        if(!root) return true;

        if(root->val >= right || root->val <= left) return false; // current val is out of bounds

        // update bounds when calling children nodes
        return dfs(root->left, left, root->val) && dfs(root->right, root->val, right); 
    }
    bool isValidBST(TreeNode* root) {

        if(!root) return true;
        return dfs(root, LONG_MIN, LONG_MAX); // start bounds at negative and positive "infinity"
    }
};

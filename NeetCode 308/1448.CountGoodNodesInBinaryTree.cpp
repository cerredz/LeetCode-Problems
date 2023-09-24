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
          Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
          Return the number of good nodes in the binary tree.
    */
    void dfs(TreeNode* root, int& result, int max_val) {
        
        if(!root) return;

        // max value on current path
        max_val = max(max_val, root->val);

        // check if children nodes are greater than max value on path, if so increment the number of "good nodes"
        if(root->left && max_val <= root->left->val) result++;
        if(root->right && max_val <= root->right->val) result++;

        // run the same thing on every nodes in the tree
        dfs(root->left, result, max_val);
        dfs(root->right, result, max_val);
        
    }
    int goodNodes(TreeNode* root) {
        int res = 1;
        dfs(root, res, root->val);
        return res;
    }
};

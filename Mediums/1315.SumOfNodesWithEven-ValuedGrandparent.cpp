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
    Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.
    A grandparent of a node is the parent of its parent if it exists.
*/
    
    void dfs(TreeNode* root, int& sum) {

        if(!root) return;

        if(root->val % 2 == 0) {
            // even node, add all of the grandparent node vals to sum
            if(root->left && root->left->left) sum += root->left->left->val;
            if(root->left && root->left->right) sum += root->left->right->val;
            if(root->right && root->right->right) sum += root->right->right->val;
            if(root->right && root->right->left) sum += root->right->left->val;
        }

        // traverse through the whole tree, checking the grandparents at each node
        dfs(root->left, sum);
        dfs(root->right, sum);

    }

    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

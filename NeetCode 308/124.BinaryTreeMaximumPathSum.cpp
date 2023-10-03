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
      A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once.
      Note that the path does not need to pass through the root. The path sum of a path is the sum of the node's values in the path.
      Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
    int dfs(TreeNode* root, int& maxVal) {

        if(!root) return 0;

        int left = max(0, dfs(root->left, maxVal));  
        int right = max(0, dfs(root->right, maxVal));
        // if the max sum of the left or right child is negative, then we replace it with 0

        maxVal = max(maxVal, root->val + left + right); // actual result

        return max(left, right) + root->val; // calculates the value of the current path
        
    }

    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};

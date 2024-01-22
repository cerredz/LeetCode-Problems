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
    int difference;
public:
    /*
        Problem:
          Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val|
          and a is an ancestor of b. A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

        Approach:
            1. traverse the tree, and while traversing keep track of the minimum
                and maximum node values seen
            2. During the traversal, keep track of the largest gap between the min and 
                max values found, and return that 
    */
    void dfs(TreeNode* root, int min_val, int max_val) {

        if(root == nullptr) return;
        
        min_val = min(root->val, min_val);
        max_val = max(root->val, max_val);
        difference = max(difference, max_val - min_val);

        dfs(root->left, min_val, max_val);
        dfs(root->right, min_val, max_val);

    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(root == nullptr) return 0;
        difference = 0;
        dfs(root, root->val, root->val);
        return difference;


    }
};

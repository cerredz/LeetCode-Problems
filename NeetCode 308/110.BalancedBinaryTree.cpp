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
      Given a binary tree, determine if it is  height-balanced.


*/
    pair<bool,int> dfs(TreeNode* root){

        if(!root){
            return {true, 0};
        }

        //will be taking a "bottom-up" approach, so trasverse through the subtrees first
        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);

        //calculate the height of the left and right subtree
        int balancedHeight = abs(left.second - right.second);
        bool balanced = true;
        

        if(!left.first || !right.first || balancedHeight > 1){
            //if left or right ever records a "false", we want to make sure it stays false throughout the traversal
            balanced = false;
        }

        //as you go up the tree the heights will be increasing
        return {balanced, 1 + max(left.second, right.second)};
    }


    bool isBalanced(TreeNode* root) {
        
        if(!root){
            return true;
        }

        //dfs returns a pair because we need to know whether or not the subtree / node is balanced(bool) and the height of the subtree (int)
        pair<bool, int> res = dfs(root);

        return res.first;

        
        

    }
};

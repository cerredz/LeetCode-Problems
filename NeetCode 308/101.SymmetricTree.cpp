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
        Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/
    // helper function for checking if two nodes are symmetrical
    bool dfs(TreeNode* leftNode, TreeNode* rightNode) {


        if(!leftNode && !rightNode){
            // havent run into two different nodes, so we return true
            return true;
        }

        if(!leftNode || !rightNode || leftNode->val != rightNode->val){
            // either missing node, or different value between nodes, return false
            return false;
        }

        // need tree to be symmetric at EVERY node, so return dfs at left AND right subtrees
        return dfs(leftNode->left, rightNode->right) && dfs(leftNode->right, rightNode->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }

        bool symmetric = dfs(root->left, root->right);
        return symmetric;
    }
};

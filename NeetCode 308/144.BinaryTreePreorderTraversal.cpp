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
      Given the root of a binary tree, return the preorder traversal of its nodes' values.

*/
    vector<int> res;

    vector<int> preorderTraversal(TreeNode* root) {
        

        //add value of node onto res first 
        if(root){
            res.push_back(root->val);
        }

        //then traverse through left nodes 
        if(root && root->left){
            preorderTraversal(root->left);
        }

        //lastly traverse through right nodes
        if(root && root->right){
            preorderTraversal(root->right);
        }

        return res;
    }
};

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
    Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        
        //traverse through the left nodes
        if(root && root->left){
            inorderTraversal(root->left);
        }

        //add current node to res
        if(root) {
            res.push_back(root->val);
        }   
       
        //traverse through the right nodes
        if(root && root->right){
            inorderTraversal(root->right);
        }

        
        return res;
    }
};

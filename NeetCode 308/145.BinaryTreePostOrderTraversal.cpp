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
      Given the root of a binary tree, return the postorder traversal of its nodes' values.

*/

    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        
        //traverse through left nodes
        if(root && root->left){
            postorderTraversal(root->left);
        }
        
        //traverse through right nodes
        if(root && root->right){
            postorderTraversal(root->right);
        }

        //push nodes onto res after traversing through all the nodes
        if(root){
            res.push_back(root->val);
        }
        return res;
    }
};

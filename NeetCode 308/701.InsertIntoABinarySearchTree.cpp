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
      You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the 
      insertion. It is guaranteed that the new value does not exist in the original BST. Notice that there may exist multiple valid ways for the 
      insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root){
            root = new TreeNode(val);
        }

        //use another treenode to traverse through tree
        TreeNode* curr = root;

        while(curr){
            
            //insert into tree if child nodes are null
            if(curr->val < val && !curr->right) curr->right = new TreeNode(val);
            
            if(curr->val > val && !curr->left) curr->left = new TreeNode(val);

            //traverse down the tree based on the value of our current node
            if(curr->val > val){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        //return new tree
        return root;

    }
};

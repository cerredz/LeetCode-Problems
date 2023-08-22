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
      Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, 
      and return it.

      Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

*/
    string res = "";
    string tree2str(TreeNode* root) {
        
        if(!root){
            return "";
        }
        
        //add current value to res
        res += to_string(root->val);

        
        //if node has children, visit the left node
        if(root->left || root->right){
            res += "(";
            tree2str(root->left);
            res += ")";
        }

        //if no left node, visit the right node
        if(root->right){
            res += "(";
            tree2str(root->right);
            res += ")";
        }

        return res;

        
    }
};

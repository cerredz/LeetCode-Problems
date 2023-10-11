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
    Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.\
    As a reminder, a binary search tree is a tree that satisfies these constraints:
    The left subtree of a node contains only nodes with keys less than the node's key. 
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

*/
    // helper function to calculate the sum of all the nodes values in the tree
    void treeSum(TreeNode* root, int& sum) {

        if(root->left) treeSum(root->left, sum);

        sum += root->val;

        if(root->right) treeSum(root->right, sum);
    }

    // helper function to update the node's values based on the sum of all the nodes
    void createGreaterTree(TreeNode* root, int& sum) {

        if(root->left) createGreaterTree(root->left, sum);

        // update the root's value using the sum
        int original_node_val = root->val;
        root->val = sum;
        sum -= original_node_val;

        if(root->right) createGreaterTree(root->right, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        treeSum(root, sum); // calculate the total sum of all the values in tree 
        createGreaterTree(root, sum); // use the sum combined with an in-order traversal to update the values of the nodes in the tree 
        return root;
    }
};

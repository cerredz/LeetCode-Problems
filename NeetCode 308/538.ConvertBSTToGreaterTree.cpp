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
      Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original
      BST is changed to the original key plus the sum of all keys greater than the original key in BST.
      As a reminder, a binary search tree is a tree that satisfies these constraints: The left subtree of a node contains only nodes with keys less than the node's key.
      The right subtree of a node contains only nodes with keys greater than the node's key. Both the left and right subtrees must also be binary search trees.

*/
    // helper function to calculate the total sum in the tree
    void calculateTreeSum(TreeNode* root, int &sum) {

        if(root->left) {
            calculateTreeSum(root->left, sum);
        }

        sum += root->val;

        if(root->right) {
            calculateTreeSum(root->right, sum);
        }
    }

    // helper function to create a new tree
    TreeNode* createGreaterTree(TreeNode* root, int& currentSum) {

        if(root->left){
            createGreaterTree(root->left, currentSum);
        }
        // since we are doing an in-order traversal, we can just replace the current node's value with the current sum since as we traverse the sum is going to keep decreasing
        int temp = root->val;
        root->val = currentSum;
        currentSum-= temp;

        if(root->right) {
            createGreaterTree(root->right, currentSum);
        }

        return root;

    }

    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;

        int sum = 0;
        calculateTreeSum(root, sum); // calculates the sum of all node vals in root
        return createGreaterTree(root, sum); // creates the greater tree
    }
};

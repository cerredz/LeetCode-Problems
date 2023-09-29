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
            Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the
            tree.

        Approach:
            1. Simple just perform a in-order traversal, and as a we traversing add the current number into a
                vector
            2. After traversing all nodes, simply just return the number located in the vector at the index
                k - 1 (the tree is 1-indexes and the vector is 0-indexed so we return k-1 and not k)
    */

    // helper in-order traversal function
    void dfs(TreeNode* root, vector<int> &nums){

        
        if(root->left) {
            dfs(root->left, nums);
        }

        nums.emplace_back(root->val); 

        if(root->right){
            dfs(root->right, nums);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root) {
            return 0;
        }

        vector<int> nums;
        dfs(root, nums); // perform in-order traversal
        return nums[k - 1];

    }
};

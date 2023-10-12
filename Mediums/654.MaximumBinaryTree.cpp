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
   You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:
   Create a root node whose value is the maximum value in nums. Recursively build the left subtree on the subarray prefix to the left of the maximum value.
   Recursively build the right subtree on the subarray suffix to the right of the maximum value. Return the maximum binary tree built from nums.
*/
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        // base case
        if(nums.size() == 0) return nullptr;

        int maxVal = INT_MIN, index = 0;
        // get the greatest number in nums, and the index of the greatest number in nums
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                index = i;
            }
        }

        // create the root node with the greatest value
        TreeNode* root = new TreeNode(maxVal);

        // recursively build the left and right subtrees
        vector<int> left (nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin() + index + 1, nums.end());

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;

        
    }
};

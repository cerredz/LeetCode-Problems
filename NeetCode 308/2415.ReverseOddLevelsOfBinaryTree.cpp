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
    
    Problem:
      Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
      For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
      Return the root of the reversed tree. A binary tree is perfect if all parent nodes have two children and all leaves are on the same level. 
      The level of a node is the number of edges along the path between it and the root node.

    void reverse(TreeNode* node1, TreeNode* node2, int level) {
        if (!node1) {
            return;
        }

        if (level % 2 == 1) {
            // odd level reached, swap two nodes
            int temp = node1->val;
            node1->val = node2->val;
            node2->val = temp;
        }

        // traverse in a way so that node1 and node2 go from outward to inward
        reverse(node1->left, node2->right, level + 1);
        reverse(node1->right, node2->left, level + 1);
    }


    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 1);
        return root;
    }
};

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
          For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
          A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
          Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.
        Approach:
            1. notice how in example 1 every node in root 1 has the same children node
             VALUES as every node in root 2. This is beacause the number of flips you do to make the tree
            equivalent are irrelevant, and the actual node values are the only thing that matters
            2. Notice that for every time we traverse a node in root1 or root2, there are 4 ways
                we can combine their children nodes when checking the values of each of them.
                (root1.left, root2.left)(root1.left, root2.right)(root1.right, root2.left)(root1.right,root2.right)
            3. We will do check these 4 combinations for every node, and every time we check we 
                need to make sure that root1 and root2 have the same node VALUES, does not have to be
                in the same position. If even once for all four combinations there are different values
                then the tree is not equivalent no matter how many flips, so we can return false
    */
    
    // helper function to check if two trees are equivalent
    bool equivelentTree(TreeNode* root1, TreeNode* root2) {

        if((!root1 && !root2)) return true; // made it to root node without any false returns, return true

        if((!root1 && root2) || (root1 && !root2) || (root1->val != root2->val )) return false;
        
        // check all 4 combinations of root1 and root2 children nodes
        bool sameTree = equivelentTree(root1->left, root2->left) && equivelentTree(root1->right, root2->right);

        return sameTree || equivelentTree(root1->left, root2->right) && equivelentTree(root1->right, root2->left);
    }


    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        return equivelentTree(root1, root2);
    }
};

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
            Given the root of a binary tree, return the leftmost value in the last row of the tree.
            
        Approach:
            1. We will implement a level-order traversal, and we will save the first node on 
                every level's value into a variable. By the time we are done traversing the tree
                this variable will have the leftmost value on the last row of the tree
    */
    int findBottomLeftValue(TreeNode* root) {
        

        queue<TreeNode*> q;
        int leftMostVal = 0;
        q.push(root);

        // perform level order traversal
        while(!q.empty()){
            int n = q.size();
            leftMostVal = q.front()->val; // current leftmost node

            for(int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) {
                    q.push(curr->left);
                }

                if(curr->right) {
                    q.push(curr->right);
                }
            }
        }

        return leftMostVal;
    }
};

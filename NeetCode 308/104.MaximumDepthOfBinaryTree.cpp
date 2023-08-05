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
      Given the root of a binary tree, return its maximum depth.
      A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/
    int maxDepth(TreeNode* root) {
        
        if(!root){
            return 0;
        }

        //we will be performing a level-order traversal while keeping count of the depth to solve this problem, since every iteration = 1 depth

        //declare variables 
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);

        //perform a level order traversal
        while(!q.empty()) {

            int n = q.size();
            //keep count of the depth
            depth++;

            //add the next level to the queue
            for(int i = 0; i < n; i++) {

                if(q.front()->left){
                    q.push(q.front()->left);
                }

                if(q.front()->right){
                    q.push(q.front()->right);
                }

                q.pop();
            }
        }

        return depth; 
    }
};

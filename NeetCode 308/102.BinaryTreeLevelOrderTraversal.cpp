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
    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

*/
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> res; 
        if(!root){
            //edge case
            return res;
        }

        queue<TreeNode*> q; // use queue for level order traversal
        q.push(root);

        while(!q.empty()){

            //calculate size of q before adding anything to it
            int n = q.size();
            vector<int> temp;

            //traverse through the current level
            for(int i = 0; i < n; i++) {

                //add current node to the level-array
                TreeNode* current_node = q.front();
                temp.emplace_back(current_node->val);

                //push next level into the queue
                if(current_node->left){
                    q.push(current_node->left);
                }

                if(current_node->right){
                    q.push(current_node->right);
                }

                //remove current level from the queue
                q.pop();

            }

            //add current level to res
            res.emplace_back(temp);
        }

        return res;
    }
};

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
    Approach:
        1. Notice that at each level of the tree, as we traverse the current level going from left -> right is
            really just the opposite of going from right -> left. We will use this information in our solution.
        2. Because we are using a level-order traversal, we can keep track of the level we are on. We will start
            our level order traversal the stanward way, but notice that every other level, after we finish adding
            all of the values to an array, we must reverse the value to simulate traversing from right -> left
        3. This is where keep tracking of the levels come into play, if the current level is even, then
            reverse the values in that level, otherwise just traverse through the level and insert the values
            into a 2d array. Once we reach the next level increment the level counter variable
        4. Repeat step 3 for all levels of the tree
*/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        //perform a standard level-order traversal while keep track of the level
        while(!q.empty()){

            int n = q.size();
            vector<int> curr_level; 

            //traverse through the current level
            for(int i = 0; i < n; i++) {

                //add current level values to array
                TreeNode* curr_node = q.front();
                q.pop();
                curr_level.emplace_back(curr_node->val);


                //add next level to the queue
                if(curr_node->left){
                    q.push(curr_node->left);
                }

                if(curr_node->right){
                    q.push(curr_node->right);
                }
            }

            if(level % 2 == 0){
                //every 2 level simulate right -> left traversal
                reverse(curr_level.begin(), curr_level.end());
            }
            level++;
            res.emplace_back(curr_level);
        }
        return res;
    }
};

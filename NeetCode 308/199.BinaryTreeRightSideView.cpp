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
        1. The right side of the tree is not always on the right side of the original root, in other words there
            can be a node on the left half side of the tree that is still on the "right side view" as the problem
            describes
        2. The thing that makes a node standing on the right side of the tree, is that it is the last node
            in the level that it is in the tree, and we will use this information to solve the problem
        3. All we have to do is perform a level-order traversal, and add the last node in each level to our
            answer
*/
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        if(!root){
            return res;
        }

        queue<TreeNode*> q; // queue for level-order traversal
        q.push(root);

        while(!q.empty()){

            int n = q.size();

            //traverse current level
            for(int i = 0; i < n; i++) {

                TreeNode* current_node = q.front();

                //if last node in level, add it to res
                if(i == n-1){
                    res.emplace_back(current_node->val);
                }

                //add next level to the queue
                if(current_node->left){
                    q.push(current_node->left);
                }

                if(current_node->right){
                    q.push(current_node->right);
                }

                //remove current level
                q.pop();
            }
        }

        return res;
    }
};

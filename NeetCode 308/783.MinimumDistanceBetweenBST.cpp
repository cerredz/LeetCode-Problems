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

    int minDiffInBST(TreeNode* root) {
        
        if(!root){
            // edge case
            return 0;
        }

        queue<TreeNode*> q;
        priority_queue<int> heap;
        q.push(root);

        // implement level order traversal
        while(!q.empty()) {

            int n = q.size();

            //traverse through current level
            for(int i = 0; i < n; i++){

                TreeNode* curr_node = q.front();
                heap.push(curr_node->val);

                // add next level to the queue
                if(curr_node->left){
                    q.push(curr_node->left);
                }

                if(curr_node->right){
                    q.push(curr_node->right);
                }
                //remove current level from the q
                q.pop();

            }
        }

        int current_value = heap.top();
        int minimum_difference = heap.top();
        heap.pop();
        // find minimum difference between all of the nodes
        while(!heap.empty()){
            
            int current_difference = current_value - heap.top();
            minimum_difference = min(minimum_difference, current_difference);
            current_value = heap.top();
            heap.pop();
        }
        return minimum_difference;
        
    }
};

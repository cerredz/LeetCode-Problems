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
        1. This problem can be completed with a level order traversal
        2. At each level we will keep track of a boolean value to see if a node is
            missing. Once we "find" a missing node we will set this boolean value, 
            call it missing, to true
        3. When adding the next level of nodes to the binary tree, if we discover
            either a left or right child node when "missing" is true then this means
            that the tree is not complete, and we can return false

*/
    bool isCompleteTree(TreeNode* root) {
        
        if(!root) return true;

        queue<TreeNode*>q;
        q.push(root);

        bool missing_node = false; // keeps track of a missing node

        // implement modified level-order traverse algorithmn
        while(!q.empty()) {

            int n = q.size();

            for(int i = 0; i < n; i++) {
                TreeNode* curr_node = q.front();
                q.pop();

                if(!curr_node){
                    // need nullptr check because we are using terniary structures 
                    continue;
                }

                if(missing_node && (curr_node->left || curr_node->right)){
                    // a node appears to the right of a missing node, or on the next level
                    return false;
                }

                // push left node if present, set missing node to true if not
                q.push(curr_node->left ? curr_node->left : (missing_node = true, nullptr));

                if(missing_node && curr_node->right){
                    // missing left node and not right node
                    return false;
                }
                
                // push right node if present, set missing node to true if not
                q.push(curr_node->right ? curr_node->right : (missing_node = true, nullptr));
            
            }
        }
        return true;

    }
};

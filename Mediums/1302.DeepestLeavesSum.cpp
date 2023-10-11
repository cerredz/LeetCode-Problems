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
      Given the root of a binary tree, return the sum of values of its deepest leaves.
    Approach:
        1. Store each level of nodes into a list of nodes, reset this list after every level of a 
            level-order traversal. After traversing the entire tree, the last level will be present in
            this list, so we can iteratre though the list and add up the values
*/
    int deepestLeavesSum(TreeNode* root) {
        
        vector<int> lowestLevel; // will store lowest level values at the end
        queue<TreeNode*> q; // need queue for level-order traversal
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            // create a temporary list to store the values of the current level
            vector<int> currLevel;
            for(int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                currLevel.emplace_back(curr->val);
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }

            lowestLevel = currLevel; // update lowestLevel to the lowest level
        }
        int sum = 0;
        for(int i : lowestLevel) sum += i;
        return sum;


    }
};

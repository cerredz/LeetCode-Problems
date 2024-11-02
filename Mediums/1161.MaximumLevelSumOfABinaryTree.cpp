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
  Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
  Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
*/
    int maxLevelSum(TreeNode* root) {
        pair<int, int> res; // value, level
        res.first = INT_MIN;
        res.second = 0;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        // implement level-order traversal
        while(!q.empty()) {
            int n = q.size();
            int curr_sum = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                curr_sum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(curr_sum > res.first) {
                res.first = curr_sum;
                res.second = level;
            }

            level++;
        }

        return res.second;
    }
};

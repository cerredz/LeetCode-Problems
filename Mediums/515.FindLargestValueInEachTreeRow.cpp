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
        Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed)
    
    */
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        // implement level order traversal
        while(!q.empty()) {
            int n = q.size();
            int largest = INT_MIN;

            // keep track of largest value found in each row
            for(int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();
                largest = max(largest, curr->val);
                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right) {
                    q.push(curr->right);
                }
            }
            // add largest to result
            res.push_back(largest);
        }
        return res;

    }
};

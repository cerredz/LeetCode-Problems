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
    You are given the root of a binary tree containing digits from 0 to 9 only.
    Each root-to-leaf path in the tree represents a number. For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
    A leaf node is a node with no children.

*/
    void dfs(TreeNode* root, string path, vector<string> &paths) {

        // traverse the left children nodes, while adding the left child val to the current path
        if(root->left) {
            dfs(root->left, path + to_string(root->left->val), paths);
        } 
        
        // check if current node is leaf node
        if(!root->left && !root->right) {
            paths.emplace_back(path);
        } 

        // traverse the right children nodes, while adding the right child val to the current path
        if(root->right) {
            dfs(root->right, path + to_string(root->right->val), paths);
        }
    }

    int sumNumbers(TreeNode* root) {
        vector<string> paths;
        dfs(root, to_string(root->val), paths); // get all leaf node paths
        int res = 0;

        // convert all leaf node paths to ints and add them to res
        for(int i = 0; i < paths.size(); i++) {
            res += stoi(paths[i]);
        }
        return res;
    }
};

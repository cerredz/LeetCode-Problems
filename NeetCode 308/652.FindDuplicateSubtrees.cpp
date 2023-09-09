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
      Given the root of a binary tree, return all duplicate subtrees.
    For each kind of duplicate subtrees, you only need to return the root node of any one of them.
    Two trees are duplicate if they have the same structure with the same node values.

    Approach:   
        1. We need to way to efficiently look at all of the possible subtrees of the original tree, and check whether or not a subtree occurs 
            more than once. One way we can achieve whether or not a subtree occurs more than once is by using a hashmap .
        2. One way we can get all of the possible subtrees is by using converting our traversal into a string. For example, if the array 
            form of a tree is [1,2,3] then the strings generated from this tree are "1", "2", "3", "1,2", "1,2,3".
        3. In order to achieve these strings, we can have a recursive helper function that returns a string. In the function start off by
            creating a string of the root's value. Then build the string by recursively calling the root->left and root->right. After building
            the string, check to see if the string exists in the hashMap, and if it does add the ROOT, not the string, add it to the result 
            vector
        
*/

    //helper recursvie function
    string dfs(TreeNode* root, vector<TreeNode*>& dupSubtrees, unordered_map<string, int> &subtrees) {

        if(!root) return "";

        // convert the traversal to a string
        string str = to_string(root->val) + ",";
        str += dfs(root->left, dupSubtrees, subtrees) + ",";
        str += dfs(root->right, dupSubtrees, subtrees);

        //check if the string already exists
        if(subtrees[str] == 1){
            dupSubtrees.emplace_back(root);
        }
        subtrees[str]++;
        return str; // used for parent strings
    }


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,int> map;
        vector<TreeNode*> res;
        dfs(root, res, map);
        return res;
    }
};

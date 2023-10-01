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
            The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
            Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. 
            It will automatically contact the police if two directly-linked houses were broken into on the same night.
            Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

        Approach:
           1. Notice how there is alot of repeated work that is being done to solve this problem. Take 
            number 2 for example, the reason why we know to use nodes 4 and 5 is because those nodes
            are bigger / equal to 3 + 1. In other words, we can use the parent node of each 
            node to calculate the maximum money a thief can rob at any given node. For this reason
            we can use recusion
            2. For every recursive call we will be returning a two-value pair, where the first value
                indicates the money stolen without including the root, and the second value
                indicates the money stolen including the root
            3. Traverse through the tree and calculate the maximum amont of money stolen by including and
                exlcuding the current node, and return the two-value pair

    */

    // helper function to calculate maximum money stolen
    pair<int,int> houseRobber(TreeNode* root) {

        if(!root) return pair<int,int>(0,0); // base case when root is null
        
        pair<int,int> left, right, res;

        // traverse tree first to get all null nodes taken care of
        left = houseRobber(root->left);
        right = houseRobber(root->right);

        res.first = root->val + left.second + right.second; // calculates money stolen including the root
        res.second = max(left.first, left.second) + max(right.first, right.second); // calculates money stolen excluding the root

        return res;
    }
    int rob(TreeNode* root) {
        
        pair<int,int> money = houseRobber(root);
        return max(money.first, money.second); // return max of including / excluding root node
    }
};

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
      Given the roots of two binary trees p and q, write a function to check if they are the same or not.
      Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

*/
    //keep a global variable beacause if we return false  once we are going to want to return it at the end    
    bool sameTree = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //both null nodes, still same tree
        if(!p && !q){
            return true;
        }

        //if only one node out of the two trees exist or values are not equal then they are not the same tree 
        if((!p && q) || (p && !q) || (p->val != q->val)){
            sameTree = false;
            return false;
        }

        //perform the above operations on all subtrees
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);

        return sameTree;


    }
};

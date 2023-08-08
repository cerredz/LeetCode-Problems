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
          Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
          A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

        Approach:   
            1. We will have a helper function that checks whether or not two subtrees are the same
            2. In our main function, we will traverse through the firstTree, and call our helper
                function if the value of the the current node we are at in the first tree is equal to 
                the value of the root in the second tree. Our helper function will then help us
                determine our answer
    */

    //helper function to check if two trees are the same 
    bool dfs(TreeNode* p, TreeNode* q){

        if(!p && !q){
            return true;
        }

        if((!p && q) || (p && !q) || (p->val != q->val)){
            return false;
        }

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

    
    bool isSubtree(TreeNode* firstTree, TreeNode* secondTree){
        
        if(!secondTree){
            return true;
        }

        
        //we will be using a level-order traversal to traverse through first tree
        queue<TreeNode*> q;
        q.push(firstTree);

        while(!q.empty()){

            int n = q.size();

            for(int i = 0; i < n; i++){

                //equal values found, check if first and second are same tree
                if(q.front()->val == secondTree->val){
                    if(dfs(q.front(), secondTree)){
                    //could be more than 1 values of secondTree->val in first tree, so we want to keep traversing firstTree even if dfs returns false
                        return true;
                    }
                }

                //add the next level to the queue for our level-order traversal
                if(q.front()->left){
                    q.push(q.front()->left);
                }

                if(q.front()->right){
                    q.push(q.front()->right);
                }

                q.pop();

            }
        }

        return false;

       
    }

};

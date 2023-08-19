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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
    
        if(!root1 && !root2) {
            return nullptr;
        }

        //create our node in the new combined tree
        TreeNode* mergedTree = new TreeNode();

        if(!root1 && root2){
            //root 1 doesnt exist, use root 2 to build the new node
            mergedTree->val = root2->val;
            mergedTree->left = mergeTrees(nullptr, root2->left);
            mergedTree->right = mergeTrees(nullptr, root2->right);
        }

        if(root1 && !root2){
            //root 2 doesnt exist, use root 1 to build the new node
            mergedTree->val = root1->val;
            mergedTree->left = mergeTrees( root1->left, nullptr);
            mergedTree->right = mergeTrees(root1->right, nullptr);
        }

        if(root1 && root2) {
            //both roots exist, use them to build the new tree
            mergedTree->val = root1->val + root2->val;
            mergedTree->left = mergeTrees(root1->left, root2->left);
            mergedTree->right = mergeTrees(root1->right, root2->right);
        }

        return mergedTree;


    }
};

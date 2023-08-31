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
      Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference
      (possibly updated) of the BST. Basically, the deletion can be divided into two stages: Search for a node to remove. If the node is found, 
      delete the node.

    Approach:
        1. There are 3 cases for a node to be deleted
            - case 1: they have no children, simply just deleted the node
            - case 2: they have 1 child, replace the node with this child
            - case 3: they have 2 children
        2. In the case of a node we want to delete that has two children, we are going to need to find the 
            successor in the tree, the reason why we cant just replace it with the node->right or node->left
            is because the other child might get overriden. However, if we find the successor of the node we 
            want to be deleted we can simple just swap the two nodes and the BST remains a valid BST with no  
            nodes being overwritten
        3. Traverse through the tree, and if a node's value is equal to key, then delete the node based
            on steps 1-2, if the key is not found simply return the original BST
*/
    // helper method to find the succcessor of a node in the tree
    TreeNode* findSuccessor(TreeNode* node){

        while(node->left){
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            // case 1: no children
            return nullptr;
        }

        if (root->val == key) {
            //key found

            if (!root->left) {
                // case 2: 1 child
                TreeNode* newRoot = root->right;
                delete root;
                return newRoot;
            } else if (!root->right) {
                // case 2: 1 child
                TreeNode* newRoot = root->left;
                delete root;
                return newRoot;
            } else {
                // case 3: two children
                TreeNode* successor = findSuccessor(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

};

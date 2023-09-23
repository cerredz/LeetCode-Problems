class Solution {
public:

    /* 
        Problem:
            Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder
            traversal of the same tree, construct and return the binary tree.

        Approach:
            1. Start at the rightmost postorder index, this will be our root node by definition of the post
                order traversal
            2. Find the rightmost postorder index in the inorder traversal and split the inorder array
                into two with the rightmost postorder index as the partition index
            3. Recursively set the right nodes child using the right partitioned subarray, and recursively set the left nodes child using the left partitioned subarray
    */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.size() == 0) return nullptr; // if matchingIndex is first index , inorder could be null
        TreeNode* root = new TreeNode(postorder.back()); // last node is root node
        postorder.pop_back(); 

        int matchingIndex = 0;
        
        // find matching index in inorder array
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                matchingIndex = i;
                break;
            }
        }

        // split inorder into 2 subarrays
        vector<int> leftSubTree (inorder.begin(), inorder.begin() + matchingIndex);
        vector<int> rightSubTree (inorder.begin() + matchingIndex + 1, inorder.end());
        
        // recursively set children node
        root->right = buildTree(rightSubTree, postorder);
        root->left = buildTree(leftSubTree, postorder);

        // return the root nodes created
        return root;
    }
};

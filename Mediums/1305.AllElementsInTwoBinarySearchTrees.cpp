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
          Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
        Approach:
            1. Iterate through root1 and root2, adding all of the node values to a min heap
            2. After adding all nodes to the heap, iterate through the min heap adding all of the values
                to a vector
    */

    // helper function to add all nodes values of a tree into a heap;
    void treeToHeap(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& heap) {

        if(root->left) treeToHeap(root->left, heap);

        heap.push(root->val);

        if(root->right) treeToHeap(root->right, heap);
    }


    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        // add all nodes values in root1 and root2 into a min heap
        priority_queue<int, vector<int>, greater<int>> heap;
        if(root1) treeToHeap(root1, heap);
        if(root2) treeToHeap(root2, heap);

        // transform the min heap into a vector
        vector<int> res (heap.size(), 0);
        int index = 0;
        while(!heap.empty()) {
            res[index] = heap.top();
            heap.pop();
            index++;
        }

        return res;

    }
};

/**

    Problem:You are given the root of a binary tree and a positive integer k.
    The level sum in the tree is the sum of the values of the nodes that are on the same level.
    Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
    Note that two nodes are on the same level if they have the same distance from the root.



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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        //maxHeap used for storing levels from greateast to fewest
        priority_queue<long long> maxHeap;
        
        
        queue<TreeNode*> q;
        q.push(root);
        long long levelSum = 0, levels = 0;
        
        
        //level order traversal
        while(!q.empty()) {
            
            //nodes in the current level
            int n = q.size();
            
            //sum of current level
            levelSum = 0;
            
            for(int i = 0; i < n; i++) {
                TreeNode* currentNode = q.front();
                
                if(currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                
                if(currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
                levelSum += currentNode->val;
                q.pop();
            }
            //push sum onto priority_queue
            maxHeap.push(levelSum);
            //keep track of levels
            levels++;
        }
        
        while(k > levels) { // check if k is greater than number of levels
            return -1;
        }
        
        // get kth largest level sum from the priority_queue
        for(int i = 0; i < k-1; i++) {
            maxHeap.pop();
        }

        
        return maxHeap.top();
    }
};

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
    Approach:
        1. We will be implementing a level-order traversal where we assign indexes to the nodes that we are traversing. 
            When inputted nodes into the queue make sure to also input their index
        2. At each level in our level-order traversal we start at our left node, this will be used as our starting index
            in each level. Traverse through the current level, and calculate the current node's index - leftmost index
            and keep track of the largest width found
        3. Repeat step 2 for each level while simultaneously adding nodes and their indexes to the queue, 
            and after going through all the levels return the greatest width found
*/
    
    int widthOfBinaryTree(TreeNode* root) {
        

        unsigned long long largestWidth = 0, currentWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q; // use a pair to store nodes and their indexes
        q.push({root, 1});


        // implement modified level-order traversal
        while(!q.empty()) {

            unsigned long long n = q.size();
            currentWidth = 0;
            unsigned long long leftMostNode = q.front().second; // leftmost node index

            // traverse through current level
            for(int i = 0; i < n; i++) {
                
                // get current node and current index
                TreeNode* currNode = q.front().first;
                unsigned long long index = q.front().second;

                // calculate current width
                currentWidth = index - leftMostNode + 1;
                
                // add next level of nodes and next level on indexes
                if(currNode->left) q.push({currNode->left, index * 2});
                if(currNode->right) q.push({currNode->right, index * 2 + 1});
                q.pop();
            }
            // check if bigger width found
            largestWidth = max(largestWidth, currentWidth);
            
        }

        return largestWidth;
        
    }

};

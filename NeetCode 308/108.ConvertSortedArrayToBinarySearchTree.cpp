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
          Given an integer array nums where the elements are sorted in ascending order, convert it to a  height-balanced binary search tree.

        Approach:
            1. Notice how they are giving the nums array to us in sorted order. This means
                that if we take two indexes of the array (0 and 4), then that means at the middle
                index (2), there is a balanced amount of numbers on each side. we will use this 
                information in to construct out binary tree
            2. We will be creating a helper recursive function, this function will have a left and
                right index value, so that way we can calculate the middle index. In the function
                we will create a new treeNode with the middle indexe's value, and then recursively
                call this function on the left and right subtrees of the newly created root
            3. When we call the function on the subtrees, we need to update the left and right  
                pointers. For example if the middle value of 0 and 8 is 4, then the left value of
                the middle value will be the middle value of 0 and 3, and the right value will be the 
                middle value of 5 and 8. We will continue this until the left value is bigger than the
                right value because this means that we have added all of the numbers to the treenode
    */

    //helper function to builds the balanced BST
    TreeNode* buildBST(vector<int> nums, int left, int right){

        if(left > right){
            //no more numbers left to insert
            return nullptr;
        }

        //create new TreeNode with middle value
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        //recursive call funcion on left and right subtrees while updating the left and right values
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        //simple just return what the helper function returns
        return buildBST(nums, 0, nums.size() - 1);
    }



};

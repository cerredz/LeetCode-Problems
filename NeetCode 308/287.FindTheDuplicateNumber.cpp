class Solution {
public:

/*
    Problem:
      Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this 
      repeated number. You must solve the problem without modifying the array nums and uses only constant extra space.

*/
    int findDuplicate(vector<int>& nums) {
        
        
        //implementation of floyds algorithmn
        int slow = 0, fast = 0;

        //find the first intersection between the slow and fast pointers
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast){
                break;
            }
        }

        int slow2 = 0;
        
        //find the second intersection between two slow pointers
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];

            if(slow == slow2) {
                break;
            }
        }

        return slow;
    }


};

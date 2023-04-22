class Solution {
public:
/*
-----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach(left and right) starting at the first
            and last index
        2. While the two pointers do not cross we will be checking the sum of the two numbers
            at each index every iteration
        3. If the sum is greater than the target, decrement the right pointer. This will always
            decrease the sum since the vector is arranged in sorted order
        4. If the sum is lower than the target, increment the left pointer. This will always
            increase the sum;
        5. If the sum is equal to the target we can return the two indexes of the pointers + 1
-----------------------------------------------------------------------------------------------
    Pduesocode:
        - declare left and right pointer

        - while left pointer <= right pointer:
            - calculate the sum of the numbers at each pointer

            - if sum > target:
                - decrement the right pointer
            - else if sum < target
                - increment the right pointer
            - else if sum = target
                - return each pointer in a vector + 1
------------------------------------------------------------------------------------------------
           
*/
    vector<int> twoSum(vector<int>& numbers, int target) {
        

        //declare pointers
        int left = 0, right = numbers.size() - 1;
        vector<int> res;

        //keep iterating until pointers cross
        while(left <= right) {
            //sum > target, decrement right
            if(numbers[left] + numbers[right] > target){
                right--;
            //sum < target, increment left
            } else if (numbers[left] + numbers[right] < target){
                left++;
            //two numbers that add to target found
            }else {
                
                res.emplace_back(left + 1);
                res.emplace_back(right + 1);
                break;
            }
        }

        return res;

            
        
       
    }
};

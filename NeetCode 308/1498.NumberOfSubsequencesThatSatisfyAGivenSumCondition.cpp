class Solution {
public:
/*
    Problem:
      You are given an array of integers nums and an integer target.
      Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target.
      Since the answer may be too large, return it modulo 109 + 7.
----------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a two pointer approach where we will be shrinking our pointers at
            every iteration
        2. We will start our left pointer at index 0 and our right pointer at the last index
            in nums
        3. We must first precompute the total number of subsequences between two indexs, for
            every index in nums, so so we make a separate vector for this and store
            the number of total subsequences between an n-lengthed window at every n index
        4. In order to tell if our left pointer is the minimum of a current window, and our
            right pointer is a maximum of a current window, we must sort nums first
        5. While our left pointer is <=  ourr right pointer we will check the following:
            - if the sum of them is greater than target we will decrement the right pointer
                to decrease the sum

            - if the sum of them if less than the target we will add the total number of
                subsequences between (right - left) % 10^9 + 7 to our result variable
        6. return the result variable
        
----------------------------------------------------------------------------------------------     
*/  
    int numSubseq(vector<int>& nums, int target) {
        
        //initialize pointers, result variable, and modulo value
        int leftPointer = 0, rightPointer = nums.size() - 1, res = 0;
        const int mod = 1000000007;

        //precompute to number of subsequences at each n-lengthed index
        vector<int> twoPowers(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            twoPowers[i] = (twoPowers[i - 1] * 2) % mod;
        }

        //sort the vector in order to use two pointer approach
        sort(nums.begin(), nums.end());

        //while left and right pointer do not cross
        while(leftPointer <= rightPointer) {
            
            //if sum is bigger, move right pointer inwards
            if(nums[leftPointer] + nums[rightPointer] > target) {
                rightPointer--;
            //if sum is less, update res and move left pointer inwards
            }else {
                res = (res + twoPowers[rightPointer - leftPointer]) % mod;
                leftPointer++;
            }
        }

        return res;


    }
};

class Solution {
public:

/*
    Problem:
        Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
        0 <= a, b, c, d < n a, b, c, and d are distinct. nums[a] + nums[b] + nums[c] + nums[d] == target You may return the answer in any order.
-----------------------------------------------------------------------------------------------------------------
    Approach:   
        1. The brute force solution is too slow for this problem, so we must utilize a two pointer approach to
            decreease the running time from 0(n^4) from 0(n^3)
        2. In order to use two pointers we must first sort the vector
        3. In order to find the sum of 4 numbers who add up to tagret, we must look at 4 numbers, the first two numbers
            we will be looking at will be the same as a double nested for loop
        4. The last two number we will be looking at we will be using two pointers for
        5. For every iteration of the nested loop, our first pointer will be at j + 1, and the second pointer will be
            at the last index of nums
        6. Add up the four numbers, nums[i], nums[j], nums[leftPointer], nums[rightPointer. If this sum is == target,
            then convert the four numbers into a vector and add it to a vector of a vector. If the sum is less than target
            then increment the left pointer, is the sum is greater than the target then decrement the right pointer
        7. Continue step 6 until left >= right
-----------------------------------------------------------------------------------------------------------------------
        
*/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //sort the vector in order to use two pointers
        sort(nums.begin(), nums.end());


        vector<vector<int>> res;
        int n = nums.size();

        //implement 0(n^3) two pointer algorithmn
        for(int i = 0; i < n - 3; i++) {

            //skip duplicate numbers
            if(i > 0 && nums[i] == nums[i - 1]) 
                continue;

            for(int j = i + 1; j < n - 2; j++) {

                //skip duplicate numbers
                if(j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                
                //declare left and right pointer
                int left = j + 1, right = n-1;

                //while pointers do not cross
                while(left < right) {

                    //calculate sum of four numbers
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];

                    //compare sum to target, and change pointers/res according
                    if(sum == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left+= 1;

                        //skip duplicate numbers
                        while(left < right && nums[left] == nums[left - 1]) 
                            left++;

                        //skip duplicate numbers
                        while(left < right && nums[right] == nums[right - 1]) 
                            right--;
                    } 
                    else if (sum < target) {
                        left += 1;
                    }
                       
                    else {
                        right -= 1;
                    }
                        
                }
            }
        }
        return res;
    }
};

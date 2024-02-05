class Solution {
public:
  /*
    Problem:
        You are given an array nums consisting of positive integers. You have to take each integer in the array,
        reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
        Return the number of distinct integers in the final array.
  
  */
    // helper function to reverse a passed in integer
    int reverseInteger(int num) {

        int res = 0;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    int countDistinctIntegers(vector<int>& nums) {
        

        // store unique elements in set
        unordered_set<int> distinct_nums;

        // add all numbers in nums and all reversed numbers in nums into the set
        for(const int& i : nums) {
            int reversed = reverseInteger(i);
            distinct_nums.insert(i);
            distinct_nums.insert(reversed);
        }

        return distinct_nums.size();
    }
};

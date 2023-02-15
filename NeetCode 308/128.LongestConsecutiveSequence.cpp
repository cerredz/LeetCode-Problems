class Solution {
public:
/*
    Problem:
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.
------------------------------------------------------------------------------------------------------------------------
    Approach:
        1. add all of the numbers in nums to a set
        2. Loop through the set 
            3. At the current number, if the set does not contain number - 1; that means that you have started a new 
                sequence
        4. keep track of the length of all sequences, and return the biggest one
------------------------------------------------------------------------------------------------------------------------
    Psuedocode:
        - declare set with a parameter of nums.begin and nums.end
        - declare varibles to represent the following: longestSequence, currentSequence, currentNum
        - for each number(num) in the set:
            - if the set does not contain (num-1)
                - update currentSequence and currentNum

                - while the set contains (currentNum + 1)
                    - increment currentNum and currentSequence
                
                - if the currentSequence is longer than the longestSequence
                    - set longestSequence equal to currentSequence
        
        - return longestSequence
                
        
*/
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end());//transforms nums into a set

        int longestSequence = 0, currentSequence = 1, currentNum = 0;

        for(int num : s) //loop through the set
        {
            if(!s.count(num - 1)) //evaluates to true if we reach a new sequence
            {
                currentSequence = 1;
                currentNum = num;

                while(s.count(currentNum + 1)) { // evaluates to true if there is a consecutive number in the set

                    currentSequence += 1;//keeps track of current sequence of consecutive numbers
                    currentNum += 1;
                }

                //now we must compare the currentSequence to the longestSequence, and assign the bigger sequence to longestSequence 
                longestSequence = max(longestSequence, currentSequence);
            }
        }
        return longestSequence;

    }
};

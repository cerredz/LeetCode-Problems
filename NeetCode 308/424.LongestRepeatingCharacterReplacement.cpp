class Solution {
public:
/*
    Problem:
      You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
      You can perform this operation at most k times.Return the length of the longest substring containing the same letter you can get after performing the above operations.
---------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach
        2. We will have a left and right pointer starting at the leftmost index. We will use a hashMap and 
            a max int varaiable to keep track of the most frequenct character that appears in our current
            window. If there are more than k other letters other that our max frequent letter (calculated by 
            doing right - left + 1 - maxFreq > k), then we will decrement the frequency of the letter at our 
            left pointer and increment the left pointer by 1. If there are less than k other letters other than 
            our max frequent letter, then we will compare the current window to the current max lengthed window
            and update accordingly
        3. Repeat step 2 for every index in the string s, make sure to increment the right pointer after 
            every iteration
        
*/
    int characterReplacement(string s, int k) {
        
        //declare variables
        unordered_map<char, int> m;
        int left = 0, maxFreq = 0, result = 0;

        //implement sliding window algorithmn
        for(int right = 0; right < s.length(); right++){

            //keep track of most frequent character
            m[s[right]]++;
            maxFreq = max(maxFreq, m[s[right]]);

            //case 1: more than k different letters
            if(right - left + 1 - maxFreq > k){

                //decrease window
                m[s[left]]--;
                left++;
                
            //case 2: less than k different letters
            }else {

                //increase window
                result = max(result, right - left + 1);
            }
        }

        return result;

        
    }
};
